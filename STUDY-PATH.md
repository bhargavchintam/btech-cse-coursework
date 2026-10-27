# Study Path

An index of every coursework, lab, workshop and practice repository on this account, arranged in the order it actually makes sense to study them rather than the order I took them.

Most of these are B.Tech CSE courses from REVA University, and they now live in this repo, one folder per course. Each one holds the notes, the runnable programs and the lab records for a single subject. On their own they are a pile of folders; in the order below they are a full computer-science curriculum that ends in AI systems work.

## How to use this

Work down a phase at a time. Each phase lists what to read, what to run, and what you should be able to do before moving on. Nothing here is a video course — every repo is source you compile and run, so the unit of progress is *"I ran it and changed it"*, not *"I watched it"*.

Three rules that make this work:

1. **Type the programs out, don't skim them.** Every course builds with a plain toolchain (`gcc`, `g++`, `javac`, `python3`, `octave`, `ngspice`). If it doesn't run for you, that's the lesson.
2. **Do the labs.** The `lab/` folder in each course is the graded subset — the problems that were considered the minimum bar for the subject.
3. **Keep the interview track running in parallel** from Phase 2 onward, a few problems a week, rather than saving it for the end.

## The map at a glance

| Track | Count | What it gets you |
|---|---|---|
| Foundations | 1 | Circuits |
| Programming | 5 | C, C++, Java, Python, and the summer camp |
| Core CS | 3 | Data structures, algorithm design, complexity |
| Machine & systems | 4 | Logic design, computer architecture, 8051, system software |
| OS & networks | 2 | Processes, IPC, sockets, protocols |
| Data | 3 | SQL, data mining, big data |
| ML & AI | 2 | Classical ML from scratch, then applications |
| Cloud & security | 3 | Virtualization, cloud, cryptography |
| Interview practice | 3 | 935 LeetCode solutions, 48 LLD designs, 68 HLD docs |
| AI infrastructure | 2 | CUDA/Triton kernels, LLM inference internals |
| Graduate & applied | 4 | US graduate coursework and applied analytics |

---

## Phase 0 — Engineering foundations

A first-year subject. Skip it if you only care about the software path; it's here because the degree included it and the notes are complete.

| Course | Contents |
|---|---|
| [Basic Electrical Engineering and Lab](foundations/basic-electrical/) | Unit notes, ngspice circuit simulations, Octave numericals, twelve lab experiments |

**Done when:** you can run an ngspice netlist and read the answer off it, and the Octave numericals reproduce the numbers in the notes.

---

## Phase 1 — Programming

Start here if you're starting from zero. C first, because everything in Phases 3 and 4 assumes you can read it.

| Order | Course | Contents |
|---|---|---|
| 1 | [Computer Concepts and C Programming](01-programming/c-programming/) | 219 C programs — printf through pointers, structures, files, dynamic memory, and menu-driven projects |
| 2 | [Programming with Python and Labs](01-programming/python/) | Python basics to decorators, generators and regex, pure standard library |
| 3 | [Object Oriented Programming Using C++](01-programming/cpp-oop/) | 145 C++ programs — classes through operator overloading, inheritance, templates, exceptions, STL |
| 4 | [Advanced Computer Programming and Lab](01-programming/java/) | 172 Java programs — basics to threads, collections, Swing, and projects |
| — | [Summer Training 2018](01-programming/summer-training-2018/) | Ten-week camp: core/advanced Java, HTML/CSS/JS/Bootstrap, React + Node, Python |

**Done when:** you can write a menu-driven C program with `malloc`/`free` that doesn't leak, and the same program in C++ with a class and in Python in a third the lines.

---

## Phase 2 — Core computer science

The centre of the degree. Everything after this leans on it.

| Order | Course | Contents |
|---|---|---|
| 1 | [Data Structures and Algorithms and Lab](02-core-cs/data-structures/) | 148 C programs — stacks, queues, linked lists, trees, heaps, hashing, graphs |
| 2 | [Design and Analysis of Algorithms and Lab](02-core-cs/algorithm-design/) | 83 C++ programs organised by *paradigm* — brute force, divide & conquer, greedy, DP, backtracking, branch & bound, NP |

Do them in that order and in that framing: DSA teaches you the containers, DAA teaches you the strategies for attacking a problem you've never seen. The DAA course is deliberately arranged by technique rather than by topic, which is the arrangement that transfers to interviews.

**Done when:** you can implement a BST delete with two children from memory, and, given a new problem, name the paradigm before you write any code.

**Start the interview track now** — see below.

---

## Phase 3 — Machine and systems level

How the machine actually executes what you wrote.

| Order | Course | Contents |
|---|---|---|
| 1 | [Digital Principles and Logic Design and Lab](03-machine-level/digital-logic/) | Gates to sequential circuits — VHDL and Verilog with testbenches, 74-series lab records |
| 2 | [Computer Organization and Architecture and Lab](03-machine-level/computer-organization/) | Datapath, control, pipelining, cache, addressing — C simulations plus Verilog |
| 3 | [Microcontrollers and Lab](03-machine-level/microcontrollers-8051/) | Intel 8051 — assembly, embedded C (SDCC), fourteen lab experiments |
| 4 | [System Software and Lab](03-machine-level/system-software/) | SIC/XE, assemblers, loaders, macro processors, compilers, LEX & YACC |

This is the phase most self-taught paths skip, and it's the one that later makes GPU memory hierarchies and cache-aware kernels feel obvious instead of magical.

**Done when:** you can trace an instruction through a pipelined datapath and explain a cache miss in terms of the address bits.

---

## Phase 4 — Operating systems and networks

| Order | Course | Contents |
|---|---|---|
| 1 | [Operating System and Unix Internals and Lab](04-os-networks/operating-systems/) | Processes, signals, IPC, threads, synchronization in C; scheduling, memory, deadlock, disk algorithms in C++ |
| 2 | [Computer Network Concepts and Protocols and Lab](04-os-networks/computer-networks/) | OSI/TCP-IP, framing, error control, routing, **BSD socket programming**, network tools, security — plus three term projects |

The networks course is the one to spend real time in. The socket programs are client–server pairs that run on loopback, and the three projects (a multi-client chat server on `select()`, a chunked file transfer, and a small HTTP server) are the first things here that behave like production software.

**Done when:** you can write a `select()`-based server that handles several clients without threads, and explain what happens to a packet between two hosts.

---

## Phase 5 — Data

| Order | Course | Contents |
|---|---|---|
| 1 | [Database Management System and Lab](05-data/dbms/) | Notes, runnable MySQL/SQL, PL/SQL procedures and triggers, twelve labs, a Library Management System |
| 2 | [Data Mining Techniques and Lab](05-data/data-mining/) | Preprocessing, Apriori/FP-growth, classification, clustering, regression, PCA — implemented from scratch in numpy, with scikit-learn comparisons |
| 3 | [Big Data and Hadoop](05-data/big-data-hadoop/) | HDFS, MapReduce (Java + Python streaming), Hive, Pig, HBase, Sqoop, Spark |

Normalisation and transactions first, then mining. The data-mining course writes each algorithm by hand *and* calls the library version, which is the fastest way to stop treating `sklearn` as a black box.

**Done when:** you can normalise a schema to 3NF and write Apriori without looking at the library.

---

## Phase 6 — Machine learning

| Course | Contents |
|---|---|
| [Machine Learning and Applications](06-ml/machine-learning/) | Regression through neural networks — every algorithm from scratch in numpy *and* the scikit-learn way, twelve labs, and a breast-cancer diagnosis project |

The one to read slowly. Backprop is written out in numpy; if you can follow that file line by line, the frameworks stop being mysterious.

**Done when:** you've implemented gradient descent, k-means and backprop from scratch and can say what each hyperparameter does to the result.

---

## Phase 7 — Cloud, virtualization and security

| Course | Contents |
|---|---|
| [Virtualization and Cloud Computing](07-cloud-security/virtualization-cloud/) | Virtualization, Docker, Kubernetes, AWS (boto3), Terraform/Ansible, 14 labs |
| [Cloud Computing Lab](07-cloud-security/cloud-computing-lab/) | Scheduling, load balancing, MapReduce, a mini CloudSim, consistent hashing — plus Docker/K8s/Terraform artifacts |
| [Cryptography and Network Security and Lab](07-cloud-security/cryptography/) | Classical ciphers, DES/AES, number theory, RSA/Diffie–Hellman/ElGamal, hashing, HMAC, signatures in C with OpenSSL |

**Done when:** you can containerise a service, deploy it to a local cluster, and explain why RSA is safe in terms of the factoring problem.

---

## Phase 8 — AI systems and inference

Where the earlier phases pay off. Phase 3 (memory hierarchy), Phase 4 (concurrency) and Phase 6 (the maths) are all prerequisites here.

| Repo | Contents |
|---|---|
| [llm-inference](https://github.com/bhargavchintam/llm-inference) | 28 runnable NumPy programs — MHA/MQA/GQA, KV cache, RoPE, paged attention, continuous batching, speculative decoding, int8/int4 quantization (GPTQ/AWQ/SmoothQuant), samplers, and a toy engine — plus 8 deep-dive notes |
| [gpu-kernels](https://github.com/bhargavchintam/gpu-kernels) | 15 CUDA kernels and 10 Triton kernels (tiled GEMM, warp-shuffle reductions, fused softmax, flash attention), each with a NumPy reference that verifies the maths, plus 8 performance notes |

Read the docs before the code in both. `gpu-kernels/docs/` covers the execution model, coalescing, bank conflicts, arithmetic intensity and the roofline model with real A100/H100 numbers; `llm-inference/docs/` does the same for KV-cache sizing, batching and the inference roofline.

> The CUDA and Triton kernels need an NVIDIA GPU to run. Without one, read them against the NumPy reference next to each — the reference is what pins down what the kernel computes.

**Done when:** you can size a KV cache for a given model and batch, and say whether a kernel is memory- or compute-bound before profiling it.

---

## Parallel track — interview preparation

Run this alongside Phases 2 onward, not after them.

| Repo | Contents | When |
|---|---|---|
| [leetcode](https://github.com/bhargavchintam/leetcode) | 935 solutions — Python 428, C++ 232, Java 162, C 69, SQL 40, bash 4. One problem per language, no duplicates | From Phase 2 |
| [low-level-design](https://github.com/bhargavchintam/low-level-design) | 48 object-oriented design problems, each a runnable demo — parking lot and elevator through inference server, KV-cache pool, GPU quota manager | From Phase 2 |
| [high-level-design](https://github.com/bhargavchintam/high-level-design) | 23 concept notes, 16 classic case studies, 29 ML/AI-infra system designs, all with worked capacity estimates | From Phase 4 |

Order within LeetCode: arrays and strings → hashing → two pointers and sliding window → trees → graphs → dynamic programming. The SQL set pairs with Phase 5; the design repos pair with Phase 4 onward once you know what a socket and a database actually are.

---

## Graduate coursework and applied projects

| Repo | Course / subject |
|---|---|
| [CS-519-Data-Science](https://github.com/bhargavchintam/CS-519-Data-Science) | Data science — assignments and final project (Jupyter) |
| [CSE-564-Visualization](https://github.com/bhargavchintam/CSE-564-Visualization) | Visualization — class notes, labs, final project |
| [credit-card-fraud-detection](https://github.com/bhargavchintam/credit-card-fraud-detection) | Foundations of Data Analytics — 5,000 transactions, 21 features, interactive dashboard |
| [qgis-geospatial-projects](https://github.com/bhargavchintam/qgis-geospatial-projects) | Crop health (Sentinel-2 NDVI), flood risk (AHP + DEM), urban heat island |

## Self-study, MOOCs and workshops

Reference material rather than a path — useful for a second explanation when a topic doesn't land.

| Repo | Subject |
|---|---|
| [Complete-Python-3-Bootcamp](https://github.com/Pierian-Data/Complete-Python-3-Bootcamp) (Pierian Data) | Python |
| [deep-learning-coursera](https://github.com/Kulbear/deep-learning-coursera) (Kulbear) | Deep Learning Specialization |
| [Tensorflow-in-practise-Specialization](https://github.com/ashishpatel26/Tensorflow-in-practise-Specialization) (ashishpatel26) | TensorFlow |
| [DataCamp](https://github.com/Anthonymcqueen21/DataCamp) (Anthonymcqueen21) | Data science courses |
| [learnopencv](https://github.com/spmallick/learnopencv) (Satya Mallick) | Computer vision, C++ and Python |
| [Intro to Cassandra for Developers](https://github.com/datastax-archive/workshop-intro-to-cassandra) (DataStax) | Cassandra workshop |
| [workshop-introduction-to-nosql](https://github.com/datastax-archive/workshop-introduction-to-nosql) (DataStax) | NoSQL workshop |
| [coding-interview-university](https://github.com/jwasham/coding-interview-university) (John Washam) | CS study plan |
| [system-design-interview](https://github.com/checkcheckzz/system-design-interview) (checkcheckzz) | System design |

These are other people's courses and notes, linked at their original repos. Other reference material I used the same way: HackerRank solution sets, [python-guide](https://github.com/realpython/python-guide), [CSE6363](https://github.com/ajdillhoff/CSE6363) (a graduate ML course), and [unfolding-maps](https://github.com/mehdihasan/unfolding-maps) from the Java data-structures specialization. Two graduate repos (an F1 statistics visualization project and a COVID strategic analysis) are private and so aren't linked here.

---

## Suggested schedules

**Six months, full time — CS fundamentals to employable.**

| Weeks | Focus |
|---|---|
| 1–3 | Phase 1: C, then Python |
| 4–9 | Phase 2: DSA then DAA. LeetCode starts week 4, 5 problems/week |
| 10–13 | Phase 4: OS, then networks and the socket projects |
| 14–17 | Phase 5: DBMS and data mining. SQL problems alongside |
| 18–21 | Phase 6: machine learning, end to end |
| 22–26 | Phase 7 and the design repos; build one project of your own |

**Twelve months, alongside a job — the full path.** Same order, one phase per month, Phase 3 kept in and Phase 8 as the last two months.

**Targeted — AI infrastructure.** Phase 2 → Phase 3 → Phase 4 (concurrency and sockets) → Phase 6 → Phase 8, with `high-level-design/ml-system-design/` read in parallel. Roughly four months if the fundamentals are already there.

---

*Every course and repo listed here builds and runs with a standard toolchain, with the single exception of the CUDA and Triton kernels, which need an NVIDIA GPU.*
