# set(INCLUDE_DIRECTORIES include)

add_executable(Seq_Search SeqSearch.c)
add_executable(Binary_Search BinarySearch.c)
add_executable(Block_Search BlockSearch.c)
add_executable(Bst_Search BstSearch.c)

target_include_directories(Seq_Search PRIVATE include)
target_include_directories(Binary_Search PRIVATE include)
target_include_directories(Block_Search PRIVATE include)
target_include_directories(Bst_Search PRIVATE include)

