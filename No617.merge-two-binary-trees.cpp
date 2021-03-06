#include <iostream>
#include <vector>
#include "myTools.h"
using namespace std;

/**
 * No617. 合并二叉树（递归）
 * 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为NULL 的节点将直接作为新二叉树的节点。

示例1:

输入: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
输出: 
合并后的树:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
注意:合并必须从两个树的根节点开始。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-binary-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 || t2) {
            int val = 0;
            val += (t1) ? t1->val : 0;
            val += (t2) ? t2->val : 0;
            TreeNode* node = new TreeNode(val);
            node->left = mergeTrees((t1) ? t1->left : nullptr, (t2) ? t2->left : nullptr);
            node->right = mergeTrees((t1) ? t1->right : nullptr, (t2) ? t2->right : nullptr);
            return node;
        }
        return nullptr;
    }
};

int main() {
    Solution solution;
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    TreeNode* result = solution.mergeTrees(root1, root2);
    MyTools::printTree(result);
    return 0;
}