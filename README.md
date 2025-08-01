# Lazy Susan Cabinet (Smart Home Project)

This project is a budget-friendly recreation of a smart Lazy Susan Cabinet — a rotating kitchen shelf typically used to store spices and jars. Designed as part of a smart home challenge, the system was built for under $30 using Arduino, stepper motors, and 3D-printed components.

## Project Overview

Smart home systems can automate everyday tasks, but often come with high price tags. Our advisor challenged us to replicate a real smart home product with a strict $30 budget. We chose to recreate a **motorized Lazy Susan Cabinet**, commonly priced around $300, and successfully built a working version for less than one-tenth of that cost.

## Features

- Dual rotating carousels to hold spices or jars
- Controlled via Arduino and stepper motors
- Designed for improved kitchen organization and accessibility
- Built using cost-effective materials:
  - 3D printed gears
  - CNC-routed wooden cabinet
  - Off-the-shelf electronics

## Technologies & Tools Used

- Arduino (for control logic)
- Stepper Motors (for rotation)
- 3D Printing (for custom gears)
- CNC Router (for cabinet fabrication)
- Arduino C / Embedded C (for firmware)

## Code Overview

The firmware allows users to control the rotation of each shelf by sending serial commands (integers 0–4 for the top shelf, 6–10 for the bottom). A reset command (11) returns the shelves to their original positions.

## Budget Breakdown

| Component         | Estimated Cost |
|------------------|----------------|
| Arduino          | $8             |
| Stepper Motors   | $10            |
| 3D Printed Parts | $5             |
| Wood + CNC       | $5             |
| Misc. Hardware   | $2             |
| **Total**        | **~$30**       |

## Motivation

Smart homes should be **accessible** and **affordable**. This project demonstrates how functional home automation concepts can be achieved by students or hobbyists on a budget, using creativity and cross-disciplinary skills in mechanical design, electronics, and software.

## Author
- Naafiul Hossain (Team BTHS 22 Mech)
