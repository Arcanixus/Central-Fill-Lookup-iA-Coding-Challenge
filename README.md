# Central Fill Lookup - iA Coding Challenge

Ethan Paoletti's Central Fill Lookup Coding Challenge for an SDE III Position at iA

# Original Directions

## Scenario
➢ Your program should randomly generate seed data.

➢ Your program should operate in a world that ranges from -10 to +10 (Y axis), and -10 
to +10 (X axis).

➢ Your program should assume that each co-ordinate can hold a maximum of one 
Central Fill facility.

➢ Each Central Fill facility has a unique numeric identifier (e.g., 001, 002, 003).

➢ Each central fill facility has different medications (A, B, C) as Inventory.

➢ Each medication has a non-zero price, expressed in USD. Ex: Medication A at 
Central Fill 001 costs $30.50

➢ The distance between two points should be computed as the Manhattan Distance.

## Instructions
➢ You are required to write a program which accepts a user location as a pair of coordinates and returns a list of the
three closest central fill facilities, along with the cheapest medication price for each 
central fill.

➢ Please detail any assumptions you have made (it is recommended you make strong 
assumptions and state them).

➢ Provide a brief summary of how you might change your program if you needed to 
support multiple central fills at the
same location?

➢ Provide a brief summary of how you would change your program if you were working 
with a much larger world size?

## Example Program Run

Please Input Coordinates:

```
> 4,2
Closest Central Fills to (4,2):
Central Fill 002 - $30.29, Medication A, Distance 3
Central Fill 006 - $35.20, Medication B, Distance 5
Central Fill 001 - $01.40, Medication A, Distance 12
```
