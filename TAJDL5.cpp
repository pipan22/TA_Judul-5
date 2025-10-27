#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* left;
    Node* right;
    Node(string n): name(n), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, string name) {
    if (!root) return new Node(name);
    if (name < root->name) root->left = insertNode(root->left, name);
    else if (name > root->name) root->right = insertNode(root->right, name);
    return root;
}

bool searchNode(Node* root, string name) {
    if (!root) return false;
    if (root->name == name) return true;
    if (name < root->name) return searchNode(root->left, name);
    return searchNode(root->right, name);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->name << "\n";
    inorder(root->right);
}

string findMin(Node* root) {
    if (!root) return "(kosong)";
    while (root->left) root = root->left;
    return root->name;
}

string findMax(Node* root) {
    if (!root) return "(kosong)";
    while (root->right) root = root->right;
    return root->name;
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int pilih;
    string nama;

    do {
        cout << "\n=== Kontak Ponsel (BST) ===\n";
        cout << "1. Tambah kontak\n2. Cari kontak\n3. Lihat semua (Inorder)\n";
        cout << "4. Nama pertama (A-Z)\n5. Nama terakhir (Z-A)\n";
        cout << "6. Jumlah kontak\n7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan nama kontak: ";
            cin >> nama;
            root = insertNode(root, nama);
        } else if (pilih == 2) {
            cout << "Cari nama: ";
            cin >> nama;
            cout << (searchNode(root, nama) ? "Kontak ditemukan.\n" : "Kontak tidak ditemukan.\n");
        } else if (pilih == 3) {
            cout << "Daftar kontak (urut A-Z):\n";
            inorder(root);
        } else if (pilih == 4) {
            cout << "Nama pertama (A-Z): " << findMin(root) << "\n";
        } else if (pilih == 5) {
            cout << "Nama terakhir (Z-A): " << findMax(root) << "\n";
        } else if (pilih == 6) {
            cout << "Jumlah kontak: " << countNodes(root) << "\n";
        }

    } while (pilih != 7);

    return 0;
}
