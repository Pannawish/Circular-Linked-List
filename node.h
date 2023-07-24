class NODE
{
public:
    int value;
    NODE *nextPtr;
    NODE(int n);
};
typedef NODE* NodePtr;
NODE::NODE(int n){
  value=n;
}
