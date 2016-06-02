![Grph](graph.png "graph of data generated")

# Birthday problem with montecarlo
Simulates birthday problem with monte carlo simulation.

More informations about the problem [here](https://duckduckgo.com/?q=birthday+problem).

#how to run
compile: `g++ -O3 main.cpp -o birthday.out`

run: `./birthday.out`

note the `-O3` flags, it drastically reduces time of esecutions!

#how it works
this generates `n=100000` **groups of people** with random birthday during a **year**, then checks how may groups have got almost two people born in the same day! Quiet simple.

You can check then for about 23 people the probability of find *two people with same birthday* is near **50%**!

#license
See [LICENSE](LICENSE)
