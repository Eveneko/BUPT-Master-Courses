#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

namespace HuffmanTree {

    struct Node{
        char c;
        int frequency;
        Node *left;
        Node *right;

        Node(char _c, int _frequency, Node *_left = nullptr, Node *_right = nullptr)
                : c(_c), frequency(_frequency), left(_left), right(_right) {}

        bool operator<(const Node &node) const {
            return frequency > node.frequency;
        }
    };

    class huffmanTree
    {
    private:
        std::priority_queue<Node> pq;

        void _huffmanCode(Node *node, std::string &prefix, std::map<char, std::string>& codeMap) {
            std::string tmp = prefix;
            if (node->left != nullptr) {
                prefix += '0';
                if (_isLeaf(node->left)) {
                    codeMap[node->left->c] = prefix;
                } else {
                    _huffmanCode(node->left, prefix, codeMap);
                }
            }
            if (node->right != nullptr) {
                prefix = tmp;
                prefix += '1';
                if (_isLeaf(node->right)) {
                    codeMap[node->right->c] = prefix;
                } else {
                    _huffmanCode(node->right, prefix, codeMap);
                }
            }
        }

        static bool _isLeaf(Node* node) {
            return node->left == nullptr && node->right == nullptr;
        }

    public:
        huffmanTree(const std::map<char, int> alphabet) {
            for(auto x : alphabet) {
                Node node(x.first, x.second);
                pq.push(node);
            }
            genHuffmanTree();
        }
        ~huffmanTree() {

        }
        void genHuffmanTree() {
            while(pq.size() != 1) {
                Node *left = new Node(pq.top());
                pq.pop();
                Node *right = new Node(pq.top());
                pq.pop();
                Node node('.', left->frequency + right->frequency, left, right);
                pq.push(node);
            }
        }
        void huffmanCode(std::map<char, std::string> &codeMap) {
            Node node = pq.top();
            std::string prefix;
            _huffmanCode(&node, prefix, codeMap);
        }
    };

}