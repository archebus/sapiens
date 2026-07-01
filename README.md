# PROJECT SAPIENS
* Game theory / caveman simulation style game.
* C and SDL <- low level for performance.
* Update: Emergent behavior using connectionist agent brain, biochemical drives,
and a genetic layer. Built from first principles in C.

---

## ARCHITECTURE:

**General**:
Write everything myself unless there is a clear reason not to.
External dependencies at an absolute minimum.

Profile before optimising. Measure, don't guess.

Document unusual decisions in comments. Not what the code does -> why.

Keep the world small until Sprint 7 is stable. Complexity should grow
from working systems, not assumptions.

**The Brain**:
Agent brain composed of layered systems.
Data flows DOWNWARDS each tick. The consequence layer feeds back UPWARDS
via Hebbian weight updates. Genome wraps everything as background monitor.

```
GENOME (modulates thresholds and sensitivities throughout)
|
PERCEPTION
  sight / proximity / body state / known locations
|
CONCEPT / MEMORY
  agent tags (mean, nice, danger)
  place memory (food patch, shelter, home)
  object concepts (food decays, tools)
  hebbian weights (co-activation bias)
|
DRIVE / BIOCHEMISTRY
  hunger / fear / social / novelty
  drives create pressure on the decision layer
  chemical decay and cascade dynamics
|
DECISION
  priority queue (weighted drive ranking)
  draw LUT (safety > food > social > novelty)
  commitment + interrupt (two thresholds per behaviour)
|
ACTION
  verb (pure: run, eat, ask, hide, trade)
  target (reference into place/agent memory)
  pathfinding (toward target)
|
CONSEQUENCE / REINFORCEMENT
  outcome signal (positive / negative)
  hebbian write-back to concept weights
  fitness pressure into genome over generations
|
(feedback loop back to CONCEPT layer)
```

### Some design decisions (thinking dump)
* Verb / target seperation --> e.g. direction context is implicit in a verb.
Flee implies direction. Instead verb run is attached to context. Decision tree
would decide run - [safety] with safety being a known concept.

* Interrupt thresholds: Every commited behavior has a start threshold and
a higher override threshold. The gap between them is behavioural intertia.
Genomes decide this gap width.

* Hebbian weights are memory: Past experiences live implicit in connection weights,
not as a memory bank. Network is biased by history, recognition vs category ...
learning are distinct problems --> start with category first. (stranger = risk)

* Drive heirachy emergence: safety / shelter / food / social priority is not
hardcoded in the queue logic. It emerges from drive weights. A LUT will resolve
genuine draws in priority based on hardcoded maslow heirachy.

* Time: slow time --> world ticks. Pawn movement. Fast time --> neuron layer.
Brains updates and settles WITHIN the world tick (multiple passes). So 
different clocks here. Lookup relaxation networks...

---

## SPRINTS / TODO.

### Sprint 0: env / workflow
- [x] C workflow / env. GCC clang make gdb valgrind.
- [x] K&R chapters on points and structs
- [x] Implement dynamic array ds. Push, get, free.
- [ ] Get a handle on realloc, key for perf.
- [ ] Implement simple hash map from scratch.
- [x] Test harness (assert macros)
- [x] Makefile with build, clean, test targets.

**Milestone**: Dyanmic array and hash maps passing tests under valgrind. No leaks.

### Sprint 1: neuron
- [x] neuron struct (activation / decay / fire)
- [x] update function for applied decay
- [x] stimulate function to add input single, clamped
- [x] fired predicate, return 1 on threshold
- [x] ascii render -> single character showing activation level?
- [ ] tests: simulate, decay, fire, decay, back below thresholds.

**Milestone**: Neuron I can poke from main.. [DONE!]

### Sprint 2: lobe
- [ ] lobe struct, neurons in flat array.
- [ ] width and height (grid render).
- [ ] lobe type
- [ ] lobe_tick(): update all neurons in lobe
- [ ] lobe_stimulate(index, signal)
- [ ] memory layout? Planning for this
- [ ] ascii render -> lobe grid, activation per cell.
- [ ] tests: lobe init, implicit contracts?

**Milestone**: grid of neurons I can stimulate and watch activate

### Sprint 3: connections
- [ ] Connection struct, source lobe, source neuron.
- [ ] tract as an array of connections
- [ ] tract_propogate() function
- [ ] hebbian updates, a to b firing strengthens weights
- [ ] ascii render -> lobe with lighted neurons.
- [ ] tests: propogation, weights, etc..

**Milestone**: stimulus in lobe propogates through weights. Repeat stimulus
strengths weights..

### Sprint 4: drive system
- [ ] Chemical pressure that influences lobes
- [ ] drive struct, level, decay rate, source lobe
- [ ] drive system, hunger, fear, social, novelty
- [ ] drive_tick() decays all drives, clamped.
- [ ] drive_stimulate() external event raises levels.
- [ ] wire drives to perception/concepts?
- [ ] ascii render -> show drive levels as bars?
- [ ] tests: contracts and updates are all appropraite.

**Milestone**: a hungry brain shows increased drive for food via neurons.

### Sprint 5: Decision and Action
- [ ] Convert brain activations into decision queue
- [ ] priority queue as small fixed array by weight
- [ ] write decision_resolve() scan, rank, lut for draws.
- [ ] commitment layer -> agent holds current action until threshold
- [ ] ascii render -> current commited action and queue.
- [ ] tests: override thresholds, correct? decision matching?

**Milestone**: brain with rising hunger should resolve the action for seek - food
and commit to it.

### Sprint 6: Minimal world
- [ ] give brain something dynamic to stimulate it
- [ ] cell: terrain type, resource, occupant?
- [ ] body: position, action, drive, brain
- [ ] movement system: A* pathfinding
- [ ] ascii render -> world grid / lattice.
- [ ] tests: coverage.

**Milestone**: one agent, wandering towards food, eating it, hunger dropping, 
then wandering again. Purely driven by brain state.

### Sprint 7: Multiple agents - emergence.
- [ ] Section less fleshed out. Lots of options after the prev is done.
- [ ] multiple agents with varied genomes?
- [ ] agent perception
- [ ] social action
- [ ] consequence signals
- [ ] outcomes

### Onwards:
- [ ] Porting ascii render to SDL
- [ ] More complex environment structures
- [ ] Tech advancement
- [ ] Breeding
- [ ] Tribal dynamics / group formation

---

## READING / LITERATURE
1. **Creation: Life and How to Make it (2001)** --> Creatures game, norns.
Creature architecutre in plain english. Basically expanding on this model
directly.

2. **Go to statement considered harmful** Control flow thinking. Want to
leverage this early for performance reasons.

3. **Organization of Behavior (1949)** Synaptic plasticity chapters. Neurons
that fire together wire together.

4. **The wisdom of the body (1932)** Homeostasis. Organisms maintaining equilibrium
by responding to hormone imbalance.

5. **Evolution of Cooperation (1984)** Directly relevant to the prisoners
dilema genetics layer.

6. **Introduction to genetic algorithms (1996)** Readable and practical. Covers
encoding behaviour in genomes and applying selection pressure.

7. **C programming language** Canonical C reference.

### Searches: 
* data-oriented design C
* struct of arrays vs array of structs
* Creatures Developer Resource CDR
* Creatures genome documentation brain lobe
* Fan-preserved archives of the original technical documentation.
* Search: complexity explorer santa fe institute

---
*Last edit: Sat 30 Jun 2026*
