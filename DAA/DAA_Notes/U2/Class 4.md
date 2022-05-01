### Knapsack Problem:
#### Idea:
- n items -> weights : W<sub>1</sub> - W<sub>n</sub>  -> values : V<sub>1</sub> - V<sub>n</sub> 
- knapsack of capacity : W
- To find the most valuable subset of items that fit into the knapsack
- Total subsets = 2<sup>n</sup> - 1 (excluding {}) 
- Exclude the ones which exceed 'W'
- Select the one with the max value out of the remaining
![[Pasted image 20220211094401.png]]
![[Pasted image 20220211094906.png]]
![[Pasted image 20220211095828.png]]
![[Pasted image 20220211100545.png]]
![[Pasted image 20220211101612.png]]
