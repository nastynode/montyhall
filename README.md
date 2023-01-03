# Monty Hall Problem
A gameshow shows the contestant 3 doors. Behind one of the doors is a new car. After the contestant has chosen a door, the gameshow host
opens a door the contestant did not choose to show that door has no car behind it, and gives the contestant the chance to switch their choice
door. Should the contestant switch doors? Will switching doors have the same success rate as not switching?

# Approach
Very verbose code. One function simulates the contestant sticking with their first choice, the other function simulates the contestant taking the option to switch after another door was revealed to be empty. Results are tracked and printed to terminal at the end of execution.

# To Run
(requires gcc c compiler) compile from command line with 
```make```
run 100 iterations with
```make run```
or choose the number of iterations with
```./montyhall```
