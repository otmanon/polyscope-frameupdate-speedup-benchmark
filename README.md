# fast frame update benchmark

This benchmark is used to test how fast the frame update for polyscope is. We evaluate the speed on a 100k vertex volume mesh with 345k tets.

To run the benchmark, clone the repo with 

```
git clone --recurse-submodules https://github.com/otmanon/polyscope-frameupdate-speedup-benchmark.git
```

Then you can follow a standard build routine: 
```
mkdir build/
cd build/
cmake ../
make 
```

Run the frame_update_benchmark target that is produced and you're good to go. You should see a polyscope window with a woola tet mesh (A terrifying 8 legged beast). The console should also be printing timeing costs for updating the mesh vertices with our update flag(Updating :) and without (Re-initializing)

