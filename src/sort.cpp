#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "../include/sort.h"
#include "../include/compare.h"
#include "../include/analyzer.h"

static void swap_vertices(Line* const tree, const size_t vertex1_index, const size_t vertex2_index) {
   Line temp = tree[vertex1_index];
   tree[vertex1_index] = tree[vertex2_index];
   tree[vertex2_index] = temp;
}

static void sift_subtree(Line* const tree, const size_t allowedVertices_number, const size_t root_startIndex) {
   /*size_t rootVertex_index         = rootVertex_startIndex,
          firstChildVertex_index   = rootVertex_startIndex * 2 + 1,
          greaterChildVertex_index = 0;
   int is_two_childVertices = 0;
   
   while (firstChildVertex_index < vertices_number) {
      is_two_childVertices = firstChildVertex_index + 1 < vertices_number;
      greaterChildVertex_index = firstChildVertex_index;
      
      if (compare_lines(tree[rootVertex_index].ptr, tree[firstChildVertex_index].ptr)) {
         if (is_two_childVertices)
            greaterChildVertex_index += compare_lines(tree[firstChildVertex_index].ptr,
                                                      tree[firstChildVertex_index + 1].ptr);
      }
      else if (is_two_childVertices &&
               compare_lines(tree[rootVertex_index].ptr, tree[firstChildVertex_index + 1].ptr))
         ++greaterChildVertex_index;
      else
         break;
   
      swap_vertices(tree, rootVertex_index, greaterChildVertex_index);
   
      rootVertex_index = greaterChildVertex_index;
      firstChildVertex_index = rootVertex_index * 2 + 1;
   }*/
   
   size_t root_index         = root_startIndex,
          firstChild_index   = root_startIndex * 2 + 1,
          greaterChild_index = 0;
   int is_two_childVertices = 0;
   
   while (firstChild_index < allowedVertices_number) {
      is_two_childVertices = firstChild_index + 1 < allowedVertices_number;
      greaterChild_index = firstChild_index;
      
      if (compare_lines(tree[root_index].ptr, tree[firstChild_index].ptr)) {
         if (is_two_childVertices)
            greaterChild_index += compare_lines(tree[firstChild_index].ptr,
                                                tree[firstChild_index + 1].ptr);
      }
      else if (is_two_childVertices &&
               compare_lines(tree[root_index].ptr, tree[firstChild_index + 1].ptr))
         ++greaterChild_index;
      else
         break;
      
      swap_vertices(tree, root_index, greaterChild_index);
   
      root_index = greaterChild_index;
      firstChild_index = root_index * 2 + 1;
   }
}

static void sift_tree(Line* const tree, const size_t allowedVertices_number) {
   size_t root_index = (allowedVertices_number - 1) / 2;
   
   while (root_index > 0)
      sift_subtree(tree, allowedVertices_number, root_index--);
   
   sift_subtree(tree, allowedVertices_number, 0);
}

int sort(Line* const tree, const size_t vertices_number) {
   if (vertices_number) {
      size_t allowedVertices_number = vertices_number;
   
      sift_tree(tree, allowedVertices_number);
      
      while (allowedVertices_number > 1) {
         swap_vertices(tree, --allowedVertices_number, 0);
         sift_tree(tree, allowedVertices_number);
      }
   }
   
   return 0;
}