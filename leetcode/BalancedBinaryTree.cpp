
class Solution {
	public:
		bool isBalanced(TreeNode* root) {
			return treeHeight(root) != -1;
		}

		int treeHeight(TreeNode* node) {
			if(node == nullptr) return 0;

			int leftHeight = treeHeight(node->left);
			int rightHeight = treeHeight(node->right);
			if(leftHeight == -1 || rightHeight == -1) return -1;
			if(abs(leftHeight - rightHeight) > 1) return -1;
			return max(leftHeight, rightHeight) + 1;
		}
};

