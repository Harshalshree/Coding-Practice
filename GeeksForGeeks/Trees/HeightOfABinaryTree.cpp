int height(Node* root)
{
   return root ? 1 + max(height(root->left), height(root->right)) : 0;
}
