#include "BinaryTree.h"

//public fucntions first
void BinaryTree::InsertNodeIter(int data){
	// what if the tree is empty?
	if (!root) {
		root = std::make_unique<Node>(data);
		return;
	}

	Node* curr = root.get();

	while (curr){
		if (data < curr->data){
			if (!curr->left){
				curr->left = std::make_unique<Node>(data);
				return;
			}else{
				curr = curr->left.get();
			}
		}else{
			if (!curr->right){
				curr->right = std::make_unique<Node>(data);
				return;
			}else{
				curr = curr->right.get();
			}
		}
	}
}

void BinaryTree::InsertNodeRec(int data){
	InsertNodeRec(root, data);
}

void BinaryTree::DeleteTree() {
	root.reset();
}

void BinaryTree::DeleteNodeBST(int value){
	DeleteNodeBST(root, value);
}

void BinaryTree::PrintPreorder() const{
	PrintPreorder(root.get());
}

void BinaryTree::PrintInorder() const{
	PrintInorder(root.get());
}

void BinaryTree::PrintPostorder() const{
	PrintPostorder(root.get());
}

void BinaryTree::PrintLevelOrder() const {
	if(!root) return;
	std::queue<Node*> q;
	q.push(root.get());
	while(!q.empty()){
		Node* curr = q.front();
		q.pop();
		std::cout << curr->data << " ";
		if(curr->left) q.push(curr->left.get());
		if(curr->right) q.push(curr->right.get());
	}
}

bool BinaryTree::BSTSearch(int value) const{
	return BSTSearch(value, root.get());
}

//private helper functions
void BinaryTree::PrintPreorder(const Node* node) const{
	if(!node) return;
	std::cout << node->data << " ";
	PrintPreorder(node->left.get());
	PrintPreorder(node->right.get());
}

void BinaryTree::PrintInorder(const Node* node) const{
	if(!node) return;
	PrintInorder(node->left.get());
	std::cout << node->data << " ";
	PrintInorder(node->right.get());
}

void BinaryTree::PrintPostorder(const Node* node) const{
	if(!node) return;
	PrintPostorder(node->left.get());
	PrintPostorder(node->right.get());
	std::cout << node->data << " ";
}

void BinaryTree::InsertNodeRec(std::unique_ptr<Node>& node, int data){
	if (!node){
		node = std::make_unique<Node>(data);
		return;
	}

	if (data < node->data){
		InsertNodeRec(node->left, data);
	}else{
		InsertNodeRec(node->right, data);
	}
}

bool BinaryTree::BSTSearch(int value, const Node* node) const{
	if (!node) return false;
	if (node->data == value) return true;

	if (value < node->data){
		return BSTSearch(value, node->left.get());
	}else{
		return BSTSearch(value, node->right.get());
	}
}

void BinaryTree::DeleteNodeBST(std::unique_ptr<Node>& node, int value){
	if (!node) return;

	if (value < node->data){
		DeleteNodeBST(node->left, value);
	}else if (value > node->data){
		DeleteNodeBST(node->right, value);
	}else{
		if (!node->left && !node->right){
			node.reset();
		}else if (!node->left){
			node = std::move(node->right);
		}else if (!node->right){
			node = std::move(node->left);
		}else{
			Node* curr = node->right.get();
			while (curr->left){
				curr = curr->left.get();
			}
			int minValue = curr->data;
			node->data = minValue;
			DeleteNodeBST(node->right, minValue);
		}
	}
}