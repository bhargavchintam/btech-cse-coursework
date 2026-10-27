# B.Tech CSE Coursework

My B.Tech CSE coursework from REVA University: programs, notes and labs for 21 courses, arranged as a curriculum. The courses were separate repos. This repo puts them together, one folder per course, grouped by track: programming, core CS, the machine level, OS and networks, data, machine learning, and cloud and security, plus one first-year foundations course.

These are my B.Tech CSE coursework programs and notes from REVA University, recreated and organised in 2026.

Each folder has its own README with the details and exact commands. [STUDY-PATH.md](STUDY-PATH.md) gives the order to study them in. The files were copied without their git history, so where a course README mentions its commit history, that history is in the course's original repo.

## Courses

| Folder | Contents | Toolchain |
|---|---|---|
| [01-programming/c-programming](01-programming/c-programming/) | **Computer Concepts and C Programming.** 219 C programs, basics to projects, plus the lab manual exercises. | ANSI C, gcc, make |
| [01-programming/python](01-programming/python/) | **Programming with Python and Labs.** Basics to advanced in pure standard library: fundamentals, data structures, OOP, files, then decorators, generators, regex and projects. | Python 3, standard library only |
| [01-programming/cpp-oop](01-programming/cpp-oop/) | **Object Oriented Programming Using C++.** 145 programs from basics through operator overloading, inheritance, polymorphism, templates, exceptions, file handling and the STL, plus 16 lab programs. | C++14, g++ |
| [01-programming/java](01-programming/java/) | **Advanced Computer Programming and Lab.** 172 Java programs from basics to threads, collections, Swing and projects, plus the lab exercises. | Java, plain JDK (javac) |
| [01-programming/summer-training-2018](01-programming/summer-training-2018/) | **Summer Training 2018.** Exercises and mini projects from a ten-week camp in Bengaluru: core and advanced Java, HTML/CSS/JS/Bootstrap, React 16 + Node, and basic Python. | javac, a browser, Node and npm, Python 3 |
| [02-core-cs/data-structures](02-core-cs/data-structures/) | **Data Structures and Algorithms and Lab.** 148 C programs from analysis and recursion to graphs and algorithm design, plus the numbered lab exercises. | ANSI C, gcc, make |
| [02-core-cs/algorithm-design](02-core-cs/algorithm-design/) | **Design and Analysis of Algorithms and Lab.** 83 C++ programs organized by design paradigm (brute force, divide & conquer, greedy, DP, backtracking, branch & bound, NP), plus the numbered lab exercises. | C++14, g++, make |
| [03-machine-level/digital-logic](03-machine-level/digital-logic/) | **Digital Principles and Logic Design and Lab.** Unit notes, VHDL and Verilog designs with testbenches, C simulations, and 74-series lab records. | GHDL, Icarus Verilog, gcc |
| [03-machine-level/computer-organization](03-machine-level/computer-organization/) | **Computer Organization and Architecture and Lab.** Unit notes, C simulations of the classic algorithms, Verilog with testbenches, and the twelve lab experiments. | Icarus Verilog, gcc (C99), make |
| [03-machine-level/microcontrollers-8051](03-machine-level/microcontrollers-8051/) | **Microcontrollers and Lab (Intel 8051).** Unit notes, assembly programs, embedded C, and the fourteen lab experiments. | 8051 assembly (Keil / ASEM-51), SDCC |
| [03-machine-level/system-software](03-machine-level/system-software/) | **System Software and Lab.** SIC/XE, assemblers, loaders, macro processors, compilers; LEX and YACC programs and C system programs. | flex, yacc (bison), gcc |
| [04-os-networks/operating-systems](04-os-networks/operating-systems/) | **Operating System and Unix Internals and Lab.** Processes, signals, IPC, threads and synchronization in C; scheduling, memory, deadlock and disk in C++. | cc (C, pthreads), c++ (C++11) |
| [04-os-networks/computer-networks](04-os-networks/computer-networks/) | **Computer Network Concepts and Protocols and Lab.** OSI/TCP-IP layers, framing, error control, routing, socket programming, network tools, security, plus labs and three term projects. | g++ (C++14, BSD sockets), Python 3, make |
| [05-data/dbms](05-data/dbms/) | **Database Management System and Lab.** Notes, runnable MySQL/SQL, PL/SQL procedures and triggers, twelve lab experiments, and a Library Management System project. | MySQL / MariaDB |
| [05-data/data-mining](05-data/data-mining/) | **Data Mining Techniques and Lab.** Preprocessing, association rules (Apriori/FP-growth), classification, clustering, regression, PCA and more, implemented from scratch with numpy/pandas, plus sklearn comparisons and labs. | Python 3, numpy, pandas, scikit-learn, scipy |
| [05-data/big-data-hadoop](05-data/big-data-hadoop/) | **Big Data and Hadoop.** Notes and labs: HDFS, MapReduce (Java and Python streaming), Hive, Pig, HBase, Sqoop, Spark, plus 14 lab exercises. | Hadoop 3.x, Spark 2.4, Hive, Pig, HBase, Sqoop |
| [06-ml/machine-learning](06-ml/machine-learning/) | **Machine Learning and Applications.** Core to advanced ML: notes, from-scratch and scikit-learn implementations with visualizations, twelve labs, and a breast-cancer diagnosis project. | Python 3, numpy, pandas, matplotlib, scikit-learn, seaborn |
| [07-cloud-security/virtualization-cloud](07-cloud-security/virtualization-cloud/) | **Virtualization and Cloud Computing.** Notes and labs: virtualization, Docker, Kubernetes, AWS (boto3), Terraform/Ansible, plus 14 lab exercises. | VirtualBox/KVM, Docker, Kubernetes, AWS CLI and boto3, Terraform, Ansible |
| [07-cloud-security/cloud-computing-lab](07-cloud-security/cloud-computing-lab/) | **Cloud Computing Lab.** Python simulations (scheduling, load balancing, MapReduce, a mini CloudSim, consistent hashing), Java, Docker/Kubernetes/Terraform artifacts, AWS/GCP CLI scripts, and hands-on lab records. | Python 3 (standard library), javac, Docker, Kubernetes, Terraform |
| [07-cloud-security/cryptography](07-cloud-security/cryptography/) | **Cryptography and Network Security and Lab.** Classical ciphers, DES/AES, number theory, RSA/Diffie-Hellman/ElGamal, hashing, HMAC and signatures in C. | cc, OpenSSL 3 (libcrypto) |
| [foundations/basic-electrical](foundations/basic-electrical/) | **Basic Electrical Engineering and Lab.** Unit notes, ngspice circuit simulations, Octave numericals, and the twelve lab experiments. | ngspice, Octave |

## Start here

Four places to start:

- **The socket projects** in [computer-networks/projects](04-os-networks/computer-networks/projects/): a `select()` chat server that broadcasts each message to every other client, a file transfer over TCP, and a minimal HTTP/1.0 server. The TCP and UDP client-server pairs are in [08-socket-programming](04-os-networks/computer-networks/08-socket-programming/). All of it was tested on loopback.
- **Algorithm design by paradigm** in [algorithm-design](02-core-cs/algorithm-design/): the programs follow Levitin's organization, one folder per design technique, from brute force and divide & conquer to dynamic programming, backtracking and branch & bound. Each folder has a `NOTES.md` on the paradigm and its analysis.
- **ML from scratch** in [machine-learning](06-ml/machine-learning/): most units implement the algorithm twice, from scratch in numpy and the scikit-learn way, and where both exist the script prints them side by side. [mlp_scratch.py](06-ml/machine-learning/10-neural-networks/mlp_scratch.py) is a two-layer network with the forward pass and backprop done by hand.
- **COA Verilog** in [computer-organization](03-machine-level/computer-organization/): every circuit has a Verilog module and a testbench, from adders and multiplexers in [03-combinational-circuits](03-machine-level/computer-organization/03-combinational-circuits/) to counters and shift registers in [04-sequential-circuits](03-machine-level/computer-organization/04-sequential-circuits/) and a 4-bit ALU in [08-processor-and-control](03-machine-level/computer-organization/08-processor-and-control/). The lab records show the real testbench output.

## How to build

Each course README has the exact commands. In short:

| Language | Build and run | Folders |
|---|---|---|
| C | `gcc -std=c99 -Wall file.c -o prog && ./prog` (add `-lm` for `math.h`), or `make` where there is a Makefile | c-programming, data-structures, digital-logic, computer-organization, system-software, operating-systems, cryptography |
| C++ | `g++ -std=c++14 -Wall file.cpp -o prog && ./prog`, or `make` where there is a Makefile | cpp-oop, algorithm-design, operating-systems, computer-networks |
| Java | `javac File.java && java File`, one class per file | java, summer-training-2018, cloud-computing-lab |
| Python | `python3 file.py`; data-mining and machine-learning need `pip install numpy pandas scikit-learn scipy matplotlib seaborn` | python, summer-training-2018, computer-networks, data-mining, big-data-hadoop, machine-learning, virtualization-cloud, cloud-computing-lab |
| Verilog | `iverilog -o sim design.v design_tb.v && vvp sim` | digital-logic, computer-organization |
| VHDL | `ghdl -a design.vhd design_tb.vhd && ghdl -e design_tb && ghdl -r design_tb` | digital-logic |
| 8051 | `sdcc -mmcs51 file.c` for the embedded C; the assembly is for Keil µVision or ASEM-51 | microcontrollers-8051 |
| LEX and YACC | `flex file.l && gcc lex.yy.c -o prog`, and `yacc -d file.y && flex file.l && gcc y.tab.c lex.yy.c -o prog` | system-software |
| OpenSSL | `cc file.c -lcrypto -o prog` | cryptography |
| SQL | `mysql -u root`, then `SOURCE file.sql;` | dbms |
| Hadoop and Spark | `javac -cp "$(hadoop classpath)" ...` for the MapReduce jobs, `spark-submit --master local file.py` for Spark | big-data-hadoop |
| Containers and cloud | `docker build`, `docker-compose up`, `kubectl apply -f`, Terraform; the AWS scripts need your own credentials | virtualization-cloud, cloud-computing-lab |
| Circuits | `ngspice -b file.cir`, `octave file.m` | basic-electrical |
| Web | open the `.html` files in a browser; `npm install && npm start` for the Node projects | summer-training-2018 |

On Linux, build the C course with `make CFLAGS="-std=c99 -Wall -D_DEFAULT_SOURCE"`. With plain `-std=c99`, glibc does not define `M_PI`, which one program in `14-external-libraries/` uses.

## CI

[build.yml](.github/workflows/build.yml) runs `make` for the five courses that have a Makefile, compiles every Java file in java, summer-training-2018 and cloud-computing-lab with `javac`, and runs `python -m compileall -q` on the eight folders with Python code. The Hadoop MapReduce jobs are not in CI, because they need the Hadoop jars.

## License

The code is under the [MIT License](LICENSE), and the notes and lab records are under [CC BY 4.0](LICENSE-docs).
