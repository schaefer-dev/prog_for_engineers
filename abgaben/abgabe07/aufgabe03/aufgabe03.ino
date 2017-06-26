struct Node { 
  int id;
  char studentName[80]; 
  int semester;
  struct Node *left; 
  struct Node *right; 
};


struct Node *find_node(struct Node *tree , int x) { 
  while (tree != NULL) { 
    if (x < tree ->id) {
        tree = tree ->left; 
      } 
      else if (x > tree ->id) {
        tree = tree ->right; 
      } 
      else { // x == tree ->id;
        return tree; 
      }
  }
}


struct Node *find_node_rek(struct Node *tree , int x) { 
  if (tree == NULL)
    return NULL;
  else{
    if (x < tree ->id) {
        return find_node_rek(tree->left, x);
      } 
      else if (x > tree ->id) {
        return find_node_rek(tree->right, x);
      } 
      else { // x == tree ->id;
        return tree; 
      }
  }
}


void insert_node(struct Node *tree , struct Node *node) {
  if (node ->id < tree ->id) {
    if (tree ->left == NULL) {
      tree ->left = node; 
    } 
    else {
      insert_node(tree ->left , node); 
    } 
  } 
  else if (node ->id > tree ->id) {
    if (tree ->right == NULL) {
      tree ->right = node; 
    } 
    else {
      insert_node(tree ->right , node); 
    } 
  } 
  else {
    // Wert existiert schon , wird nicht ueberschrieben. 
  }

}


struct Node *create_node(int mnr, char *sname, int sem){
  struct Node *returnNode = (struct Node *)malloc(sizeof(struct Node));
  *returnNode = { mnr, *sname, sem, NULL, NULL };
  return returnNode;
}

struct Node *Database;

char * student_name(int x) {
  struct Node *result = find_node(Database, x);
  if (result != NULL)
    return result->studentName;
  return NULL;
}


  
  
void setup() {
  Serial.begin(9600);
  Serial.println("test");
  // put your setup code here, to run once:
  Database = create_node(250,"test", 5);
  
  struct Node *testNode;
  
  testNode = create_node(130, "bobby", 7);
  insert_node(Database, testNode);
  
  testNode = create_node(110, "charlie", 2);
  insert_node(Database, testNode);
  
  testNode = create_node(170, "donut", 12);
  insert_node(Database, testNode);
  
  // this guy should not appear in the list, because 130 is already "taken"
  testNode = create_node(130, "Anonymous", 0);
  insert_node(Database, testNode);

}

void loop() {
  // put your main code here, to run repeatedly:
  char *print = (student_name(130));
  Serial.println(print);

}
