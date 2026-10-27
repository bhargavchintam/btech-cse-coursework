# Edge Computing

**Definition:** **Edge computing** is a distributed computing model where data is **processed near the source of data (at the "edge" of the network)** — on or close to the device — instead of sending everything to a **central cloud / data centre**. (imp)

Goal: reduce latency + bandwidth by processing data locally.

## Why edge (the problem it solves)
- IoT devices generate huge data. Sending all of it to a far cloud = **high latency** + **bandwidth cost**.
- Some apps need **real-time** response (self-driving cars, industrial robots) — can't wait for round-trip to cloud.
- Edge processes data locally -> faster response, less data sent to cloud.

## Cloud vs Edge computing (asked prev year)

| Point | Cloud computing | Edge computing |
|-------|-----------------|----------------|
| Where processed | Central data centre (far) | Near the data source (local) |
| Latency | Higher | Lower (real-time) |
| Bandwidth use | High (all data sent) | Low (only needed data sent) |
| Best for | Big storage, heavy compute, analytics | Real-time, IoT, quick response |
| Connectivity | Needs stable internet | Can work with intermittent connection |

Edge **complements** cloud, does not replace it. Edge handles real-time part, cloud handles heavy storage + analytics.

## Characteristics
- Processing at/near the device (edge nodes, gateways).
- **Low latency**, real-time.
- Reduced bandwidth to central cloud.
- Works even with poor/intermittent connectivity.

## Advantages
- **Low latency** / faster response.
- Saves **bandwidth** (less data to cloud).
- Better privacy (sensitive data stays local).
- Reliability — works offline / patchy network.

## Disadvantages (2 marks)
- Limited compute/storage at edge devices.
- More devices to **manage + secure** (larger attack surface).
- Harder to maintain / update many distributed nodes.

## Use cases
- **IoT** sensors, **self-driving cars**, industrial automation, smart cities, healthcare monitoring, CDN, AR/VR.

## Related term — Fog computing (short)
- **Fog computing** — a layer between edge and cloud (at gateways/routers), processes data on the way to cloud. Edge is closer to the device than fog.

Exam: define edge = process data near source; contrast with cloud (latency/bandwidth); list IoT use cases.
