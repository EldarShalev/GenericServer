cmake_minimum_required(VERSION 3.5)
project(Server)

set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set(CMAKE_CXX_STANDARD 14)

add_executable(Server main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverser.cpp StringReverser.h Utils.cpp Utils.h Searchable.h Searcher.h Dfs.h Bfs.h Astar.h BestFs.h State.h Point.h SearchableMatrix.cpp SearchableMatrix.h SearcherResult.h UpdatablePriorityQueue.h Bfs.cpp Astar.cpp)