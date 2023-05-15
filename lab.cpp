#include <iostream>

using namespace std;

class Matrix {
  private:
    int rows;
    int cols;
    int body[8][8];
  public:
    Matrix(int c, int r, int array[64]){
      cols = c;
      rows = r;
      if (array != NULL){
        for (int j, i = 0; i < rows; i++){
          for (j = 0; j < cols; j++){
            body[i][j] = array[j + cols*i];
          }
        }
      }
      else {
        for (int j, i = 0; i < rows; i++){
          for (j = 0; j < cols; j++){
            body[i][j] = 0;
          }
        }
      }
    }
    
    void print(){
      for (int j, i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
          cout << body[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;
    }
    
    friend Matrix ones(Matrix &self);
    friend Matrix zeros(Matrix &self);
    friend Matrix operator*(Matrix &self, float n);
    friend bool operator==(Matrix &self, Matrix n);
    friend bool operator!=(Matrix &self, Matrix m);
    friend Matrix operator+(Matrix &self, Matrix n);
    friend Matrix operator-(Matrix &self, Matrix n);
    friend Matrix operator^(Matrix &self, Matrix n);
};

Matrix zeros(Matrix &self){
  for (int j, i = 0; i < self.rows; i++){
    for (j = 0; j < self.cols; j++){
      self.body[i][j] = 0;
    }
  }
  return self; 
}

Matrix ones(Matrix &self){
  if (cols != rows){
      cout << "Матрица не квадратная" << endl;
      return self;
  }
  for (int j, i = 0; i < rows; i++){
    for (j = 0; j < cols; j++){
      if (i == j){
        body[i][j] = 1;
      }
      else {
        body[i][j] = 0;
      }
    }
  }
  return self;
}

bool operator==(Matrix &self, Matrix n){
  for (int j, i = 0; i < self.rows; i++){
    for (j = 0; j < self.cols; j++){
      if (self.body[i][j] != n.body[i][j]){
        return false;
      }
    }
  } 
  return true;
}

Matrix operator^(Matrix &self, Matrix n){
      Matrix temp(self.rows, n.cols, NULL);
      if (self.cols != n.rows){
        cout << "Умножить невозможно" << endl;
        return n;
      }
      for (int j, i = 0; i < temp.rows; i++){
        for (j = 0; j < temp.cols; j++){
          temp.body[i][j] = 0;
          for (int k = 0; k < self.cols; k++){
            temp.body[i][j] += self.body[i][k]*n.body[k][j];
          }
        }
      }
  return temp;
}

Matrix operator*(Matrix &self, float n){
  for (int j, i = 0; i < self.rows; i++){
    for (j = 0; j < self.cols; j++){
      self.body[i][j] *= n;
    }
  } 
  return self;
}

Matrix operator+(Matrix &self, Matrix n){
  for (int j, i = 0; i < self.rows; i++){
    for (j = 0; j < self.cols; j++){
      self.body[i][j] += n.body[i][j];
    }
  } 
  return self;
}

Matrix operator-(Matrix &self, Matrix n){
  for (int j, i = 0; i < self.rows; i++){
    for (j = 0; j < self.cols; j++){
      self.body[i][j] -= n.body[i][j];
    }
  } 
  return self;
}

bool operator!=(Matrix &self, Matrix n){
    if (self ^ n == self.ones() || n ^ self == n.ones()){
      return true;
    }
    else return false;
}

int main(){
  int c, r;
  cout << "Please enter cols and rows: ";
  cin >> c >> r;
  cout << "Please enter body of matrix (exactly c*r nums): ";
  int body[c*r];
  for (size_t i = 0; i < c*r; i++){
    cin >> body[i];
  }
  Matrix M(c, r, body);
  Matrix N(c, r, NULL);
  Matrix D(c, r, NULL);
  N.ones();
  M.print();
  N.print();
  D.print();
  D = M + N;
  D.print();
  return 0;
}






