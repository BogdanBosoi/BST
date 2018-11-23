#include <cstdlib>
#include <iostream>
struct Node{

    Node *st;
    Node *dr;
    int info;
};

class BST {
	Node *root;
public:
	//Node *root;
    BST();
    Node* add(int, Node*);
	Node* minValue(Node*);
    Node* Delete(Node* temp, int);	// Dupa valoare
    bool find(int);
	void DeleteNode(int);
	Node* getNode();
	void setNode(Node*);
    void RSD(Node*);
    void SRD(Node*);
    void SDR(Node*);

    int Height();
};

void BST::DeleteNode(int value){
	root = Delete(root, value);
}

void BST::setNode(Node* arg){
	root = arg;
}

BST::BST(){
    root = NULL;
}

Node* BST::getNode(){
	return root;
}

/*void BST::add(int value){
    Node *temp = new Node;
    if(root == NULL) {
        
    }
    else{
		temp = root;
        while(temp != NULL)
            if(value < temp -> info)
                temp = temp -> st;
            else if(value > temp -> info)
                temp = temp -> dr;
		Node *New = new Node;
        New -> info = value;
		New -> st = NULL;
		New -> dr = NULL;
		temp = New;
    }
}*/

Node* BST::add(int value, Node *temp){
	if(temp == NULL) {
		temp = new Node;
		temp -> info = value;
		temp -> st = NULL;
		temp -> dr = NULL;
	}
	else
	{
		if(value < temp -> info) temp -> st = add(value, temp -> st);
		else if(value > temp -> info) temp -> dr = add(value, temp -> dr);
	}
	return temp;
}

bool BST::find(int value){
	Node *temp = new Node;
	temp = root;
	while(temp != NULL){
		if(temp -> info == value) return 1;
		else if (value < temp -> info) temp = temp -> st;
		else temp = temp -> dr;
	}
	return 0;
}

Node* BST::minValue(Node* temp){
	while(temp -> st != NULL)
		temp = temp -> st;
	return temp;
}

void BST::SRD(Node* temp){
	if(temp != NULL){
		SRD(temp -> st);
		std::cout << temp -> info << " ";
		SRD(temp -> dr);
	}
}

void BST::SDR(Node* temp){
	if(temp != NULL){
		SDR(temp -> st);
		SDR(temp -> dr);
		std::cout << temp -> info << " ";
	}
}

void BST::RSD(Node* temp){
	if(temp != NULL){
		std::cout << temp -> info << " ";
		RSD(temp -> st);
		RSD(temp -> dr);
	}
}



Node* BST::Delete(Node* temp, int value){
	
	if(temp == NULL) return temp;

	if(value < temp -> info)
		temp -> st = Delete(temp -> st, value);
	else if(value > temp -> info)
		temp -> dr = Delete(temp -> dr, value);
	else
	{
		Node* nF = temp -> dr;
		if(temp -> st == NULL){
			delete temp;
			return nF;
		}
		else if(temp -> dr == NULL){
			delete temp;
			return nF;
		}

		nF = minValue(temp -> dr);
		temp -> info = nF -> info;
		temp -> dr = Delete(temp -> dr, nF -> info);
	}
	return temp;

}

int main(){
    BST *B = new BST;
	B -> setNode(B -> add(5, B -> getNode()));
    //B -> root = B -> add(5, B->getNode());
    B -> add(7, B->getNode());
	B -> add(9, B->getNode());
    B -> add(3, B->getNode());
	B -> add(2, B->getNode());
	B -> add(8, B->getNode());
	B -> add(11, B->getNode());
	B -> SRD(B->getNode());
	std::cout << "\n";
	B -> SDR(B->getNode());
	std::cout << "\n";
	B -> RSD(B->getNode());
	std::cout << "\n";
	B->DeleteNode(2);
	std::cout << "\n";
	B -> SRD(B -> getNode());
	std::cout << B -> find(5) << "\n";
    system("PAUSE");

}
