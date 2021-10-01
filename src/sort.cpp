#include <cstring>
#include "../include/sort.h"
#include "../include/compare.h"

static void swap_vertices(Line* const tree, const size_t vertex1_index, const size_t vertex2_index) {
   Line temp = tree[vertex1_index];
   tree[vertex1_index] = tree[vertex2_index];
   tree[vertex2_index] = temp;
}

static void sift_subtree_cr(Line* const tree, const size_t vertices_number, const size_t root_startIndex) {
   size_t root_index         = root_startIndex,
          firstChild_index   = root_startIndex * 2 + 1,
          greaterChild_index = 0;
   int is_two_childVertices = 0;
   
   while (firstChild_index < vertices_number) {
      is_two_childVertices = firstChild_index + 1 < vertices_number;
      greaterChild_index = firstChild_index;
      
      if (compareReversibly_lines(tree + root_index, tree + firstChild_index)) {
         if (is_two_childVertices)
            greaterChild_index += compareReversibly_lines(tree + firstChild_index,
                                                tree + firstChild_index + 1);
      }
      else if (is_two_childVertices &&
              compareReversibly_lines(tree + root_index, tree + firstChild_index + 1))
         ++greaterChild_index;
      else
         break;
      
      swap_vertices(tree, root_index, greaterChild_index);
   
      root_index = greaterChild_index;
      firstChild_index = root_index * 2 + 1;
   }
}

static void sift_subtree_c(Line* const tree, const size_t vertices_number, const size_t root_startIndex) {
   size_t root_index         = root_startIndex,
          firstChild_index   = root_startIndex * 2 + 1,
          greaterChild_index = 0;
   int is_two_childVertices = 0;
   
   while (firstChild_index < vertices_number) {
      is_two_childVertices = firstChild_index + 1 < vertices_number;
      greaterChild_index = firstChild_index;
      
      if (compare_lines(tree + root_index, tree + firstChild_index)) {
         if (is_two_childVertices)
            greaterChild_index += compare_lines(tree + firstChild_index,
                                                          tree + firstChild_index + 1);
      }
      else if (is_two_childVertices &&
              compare_lines(tree + root_index, tree + firstChild_index + 1))
         ++greaterChild_index;
      else
         break;
      
      swap_vertices(tree, root_index, greaterChild_index);
      
      root_index = greaterChild_index;
      firstChild_index = root_index * 2 + 1;
   }
}

static void sift_tree(Line* const tree, const size_t vertices_number, const int sort_type) {
   size_t root_index = (vertices_number - 1) / 2;
   
   switch (sort_type) {
      case 1: {
         while (root_index > 0)
            sift_subtree_c(tree, vertices_number, root_index--);
   
         sift_subtree_c(tree, vertices_number, 0);
         
         break;
      }
      
      case 2: {
         while (root_index > 0)
            sift_subtree_cr(tree, vertices_number, root_index--);
   
         sift_subtree_cr(tree, vertices_number, 0);
   
         break;
      }
      
      default: {
         break;
      }
   }
  
}

int sort(Line* const tree, const size_t vertices_number, const int sort_type = 1) {
   if (vertices_number) {
      size_t allowedVertices_number = vertices_number;
   
      switch (sort_type) {
         case 1: {
            sift_tree(tree, allowedVertices_number, sort_type);
   
            while (allowedVertices_number > 1) {
               swap_vertices(tree, --allowedVertices_number, 0);
               sift_tree(tree, allowedVertices_number, sort_type);
            }
            
            break;
         }
         
         case 2: {
            sift_tree(tree, allowedVertices_number, sort_type);
   
            while (allowedVertices_number > 1) {
               swap_vertices(tree, --allowedVertices_number, 0);
               sift_tree(tree, allowedVertices_number, sort_type);
            }
   
            break;
         }
         
         default: {
            return 1;
         }
      }
   }
   
   return 0;
}