### Knapsack Problem:
#### Idea:
- n items -> weights : W<sub>1</sub> - W<sub>n</sub>  -> values : V<sub>1</sub> - V<sub>n</sub> 
- knapsack of capacity : W
- To find the most valuable subset of items that fit into the knapsack
- Total subsets = 2<sup>n</sup> - 1 (excluding {}) 
- Exclude the ones which exceed 'W'
- Select the one with the max value out of the remaining
![img1](./3.png)
![[4.png]]
![[5.png]]
![[6.png]]
![[8.png]]
