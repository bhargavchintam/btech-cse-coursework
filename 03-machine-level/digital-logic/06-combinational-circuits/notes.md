# Unit 6 — Combinational Circuits

Output depends only on the present inputs (no memory). Design steps: truth table → K-map/SOP → gate circuit.

## Half adder / full adder
Half adder: Sum = A⊕B, Carry = A·B.
Full adder: Sum = A⊕B⊕Cin, Cout = AB + BCin + ACin.
A full adder = two half adders + an OR.

## Half / full subtractor
Half: Diff = A⊕B, Borrow = A'·B.
Full: Diff = A⊕B⊕Bin, Borrow = A'B + A'Bin + BBin.

## Parallel (ripple carry) adder
n full adders chained, carry rippling from LSB to MSB. Simple but slow — the MSB waits for all carries. **Carry look-ahead** generates the carries in parallel using Gᵢ = AᵢBᵢ (generate) and Pᵢ = Aᵢ⊕Bᵢ (propagate).

## Magnitude comparator
Compares two numbers, outputs A>B, A=B, A<B. Equality = XNOR of each bit pair, ANDed.

## Multiplexer (data selector)
2ⁿ inputs, n select lines, 1 output. A 4:1 mux: Y = S1'S0'I0 + S1'S0 I1 + S1 S0' I2 + S1 S0 I3.
A mux can implement any boolean function — connect the variables to the selects and the minterm values (0/1) to the data inputs.

## Demultiplexer / decoder
Demux: 1 input routed to one of 2ⁿ outputs. Decoder: n inputs → 2ⁿ one-hot outputs; each output is one minterm, so a decoder + OR gates implements functions directly.

## Encoder
2ⁿ inputs → n-bit output. A **priority encoder** resolves multiple active inputs by taking the highest.

## Code converters / parity
Binary↔Gray, BCD→7-segment are just combinational functions derived from a truth table. Parity generator = XOR of all data bits.

## Solved

**1. Implement F(A,B,C)=Σm(1,2,6,7) with an 8:1 mux.** Tie A,B,C to selects, put F's value (0/1) on each of I0..I7 → I1=I2=I6=I7=1, rest 0.

**2. Full adder from half adders.** Sum = (A⊕B)⊕Cin; Cout = (A⊕B)Cin + AB.
