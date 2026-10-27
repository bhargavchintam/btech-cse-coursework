# 74xx series — lab IC reference

All are 14- or 16-pin DIP. Unless noted, VCC is the top-right pin and GND is the bottom-left (pin 7 on 14-pin, pin 8 on 16-pin). Full per-pin diagrams are in each lab record.

| IC | Name | Pins | Function |
|----|------|------|----------|
| 7400 | Quad 2-input NAND | 14 | 4 NAND gates |
| 7402 | Quad 2-input NOR | 14 | 4 NOR gates (note: outputs on pins 1,4,10,13) |
| 7404 | Hex inverter | 14 | 6 NOT gates |
| 7408 | Quad 2-input AND | 14 | 4 AND gates |
| 7432 | Quad 2-input OR | 14 | 4 OR gates |
| 7486 | Quad 2-input XOR | 14 | 4 XOR gates |
| 7483 | 4-bit binary full adder | 16 | A+B+C0 → S, C4 |
| 7485 | 4-bit magnitude comparator | 16 | A>B, A=B, A<B with cascade in |
| 74138 | 3-to-8 decoder | 16 | active-low outputs, 3 enables |
| 74151 | 8-to-1 multiplexer | 16 | 3 selects, Y and Y', strobe |
| 7447 | BCD to 7-segment decoder | 16 | active-low outputs, common-anode |
| 7474 | Dual D flip-flop | 14 | edge-triggered, preset/clear |
| 7476 | Dual JK flip-flop | 16 | preset/clear (active low) |
| 7490 | Decade counter | 14 | mod-2 × mod-5 = mod-10 ripple |
| 7495 | 4-bit shift register | 14 | shift right/left, parallel load |

> Pin 14 = VCC, pin 7 = GND on every 14-pin gate IC. Get this wrong and nothing works.
