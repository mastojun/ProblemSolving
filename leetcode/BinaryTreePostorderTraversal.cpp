class Solution {
	public:
		vector<int> result;

		vector<int> postorderTraversal(TreeNode *root) {
			_postorderTraversal(root);
			return result;
		}

		void _postorderTraversal(TreeNode *root) {
			if(root == NULL) return;
			_postorderTraversal(root->left);
			_postorderTraversal(root->right);
			result.push_back(root->val);
		}
};
