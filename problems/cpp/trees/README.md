# Trees

Binary trees, binary search trees, and tree traversal problems.

## Key Concepts Covered
- Tree traversals (inorder, preorder, postorder, level-order)
- Binary Search Tree (BST) operations
- Tree construction from traversals
- Lowest Common Ancestor (LCA)
- Tree diameter and height
- Binary lifting
- Morris traversal (O(1) space)
- Tree views (left, right, vertical)
- Balanced trees

## Problems in this Directory

### Tree Traversals
- [tree_traversals](tree_traversals/) - Basic tree traversals (inorder, preorder, postorder)
- [tree_inorder_iterative](tree_inorder_iterative/) - Iterative inorder
- [tree_preorder_iterative](tree_preorder_iterative/) - Iterative preorder
- [tree_levelorder](tree_levelorder/) - Level-order traversal (BFS)
- [tree_morristraversal](tree_morristraversal/) - Morris traversal (O(1) space)
- [MorrisInorderTraversel](MorrisInorderTraversel/) - Morris inorder traversal
- [preorrder_vectorTree](preorrder_vectorTree/) - Preorder with vector

### Tree Properties
- [tree_height](tree_height/) - Calculate tree height
- [tree_diameter](tree_diameter/) - Find tree diameter
- [tree_diameter2](tree_diameter2/) - Tree diameter variant
- [diameterTree](diameterTree/) - Diameter of tree
- [trees_count_nodes](trees_count_nodes/) - Count nodes in tree
- [chkBalancedTree](chkBalancedTree/) - Check if tree is balanced

### Lowest Common Ancestor (LCA)
- [tree_lca_dfs](tree_lca_dfs/) - LCA using DFS
- [LCA](LCA/) - Lowest common ancestor
- [LCAinBST](LCAinBST/) - LCA in binary search tree
- [trees_parrentarray_lca](trees_parrentarray_lca/) - LCA using parent array
- [trees_binarylifting_lca](trees_binarylifting_lca/) - LCA using binary lifting

### Tree Views
- [tree_leftview](tree_leftview/) - Left view of tree
- [tree_rightview](tree_rightview/) - Right view of tree
- [RightViewBinTree](RightViewBinTree/) - Right view binary tree
- [TopViewTree](TopViewTree/) - Top view of tree
- [trees_vertical_order_traversal](trees_vertical_order_traversal/) - Vertical order traversal
- [trees_zigzagtraversal](trees_zigzagtraversal/) - Zigzag level order

### Tree Construction
- [trees_create_tree_inorder_preorder](trees_create_tree_inorder_preorder/) - Construct from inorder+preorder
- [trees_createtree_inorder_postorder](trees_createtree_inorder_postorder/) - Construct from inorder+postorder
- [BinaryTreeFromInOrderandPostorder](BinaryTreeFromInOrderandPostorder/) - Binary tree from inorder and postorder
- [trees_design](trees_design/) - Tree design

### Binary Search Tree (BST)
- [trees_valid_bin_search](trees_valid_bin_search/) - Validate BST
- [LargestSubtreeBST](LargestSubtreeBST/) - Largest subtree that is BST

### Binary Lifting & Advanced
- [trees_binarylifting_ancestork](trees_binarylifting_ancestork/) - Binary lifting to find K-th ancestor
- [trees_bfs_binary_liftingkancstor](trees_bfs_binary_liftingkancstor/) - BFS with binary lifting for K ancestor
- [trees_bfs_parentarray](trees_bfs_parentarray/) - BFS with parent array
- [trees_findk](trees_findk/) - Find Kth element

### Special Problems
- [tree_max_xor](tree_max_xor/) - Maximum XOR in tree
- [trees_nextlink](trees_nextlink/) - Next right pointers in tree
- [serializeLevelOrder](serializeLevelOrder/) - Serialize/deserialize tree using level order

## Tips
- Master recursion for tree problems
- Use NULL checks to avoid segfaults
- Draw trees while solving
- Remember: Inorder of BST is sorted
- Practice both recursive and iterative approaches
