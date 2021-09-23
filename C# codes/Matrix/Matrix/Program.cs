using System;

namespace Matrix
{
    class Program
    {
        static void Main(string[] args)
        {
            Matrix newObj;

            Random rnd = new Random();

            double[,] arr = new double[2, 3];

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    arr[i, j] = rnd.Next(-5, 6);
                }
            }

            Console.WriteLine("All the functionality of the program:\n");

            var obj = new Matrix(); //Создали пустую матрицу
            var obj1 = new Matrix(3); //Создали квадратную матрицу размера 3х3
            var obj5 = new Matrix(3); //Создали квадратную матрицу размера 3х3
            var obj2 = new Matrix(3, 4); //Создали прямоугольную матрицу размера 3х4
            var obj3 = new Matrix(arr); //Создали матрицу, заданную в виде двумерного массива

            //Инициализируем матрицу объекта obj1 и obj5
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    obj1.Array[i, j] = rnd.Next(-5, 6);
                    obj5.Array[i, j] = rnd.Next(-5, 6);
                }
            }

            var obj4 = new Matrix(obj1.Array); //Скопировали матрицу из obj1 в obj4

            //Инициализируем матрицу объекта obj2
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    obj2.Array[i, j] = rnd.Next(-5, 6);
                }
            }

            //Здесь применяем метод ToString(). 
            //Console.WriteLine сама вызывает его, по этому дополнительного прописывать его для каждого объекта не нужно
            Console.WriteLine("\nAll matrix:\n");
            Console.WriteLine("Matrix obj1:\n" + obj1);
            Console.WriteLine("\nMatrix obj2:\n" + obj2);
            Console.WriteLine("\nMatrix obj3:\n" + obj3);
            Console.WriteLine("\nMatrix obj4 (The same matrix with obj1):\n" + obj4);
            Console.WriteLine("\nMatrix obj5:\n" + obj5);

            Console.WriteLine("\nMatrix multiplication obj1 and obj2:\n");
            newObj = obj1 * obj2;
            Console.WriteLine("\nMatrix after multiplication:\n" + newObj);

            //newObj = obj2 * obj3; Если умножим эти 2 объекта, то получим ArgumentException("Matrices cannot be multiplication!")

            Console.WriteLine("\nMatrix addition obj1 and obj4:\n");
            newObj = obj1 + obj4;
            Console.WriteLine("\nMatrix after addition:\n" + newObj);

            //newObj = obj1 + obj3; Если сложим эти 2 объекта, то получим ArgumentException("Matrices cannot be addition!");

            Console.WriteLine("\nMatrix subtraction obj1 and obj4:\n");
            newObj = obj1 - obj4;
            //Здесь будут одни нули в матрице, т.к. вычитаем из объекта obj1, который мы копировали obj4
            //Следовательно вычитаем одинаковые матрицы
            Console.WriteLine("\nMatrix after subtraction:\n" + newObj);

            //newObj = obj1 - obj3; Если вычтем эти 2 объекта, то получим ArgumentException("Matrices cannot be substraction!");

            Console.WriteLine("\nMultiply the matrix obj1 by a scalar:\n");
            newObj = obj1 * 2.5; //Скаляр может быть как целым числом, так и дробным
            Console.WriteLine("\nMatrix after multiplication by a scalar:\n" + newObj);

            Console.WriteLine("\nLet's compare some matrices:\n");
            //Сравним сначала через метод Equals
            //Они будут равны, т.к. матрицу, напомню, obj1 мы скопировали в obj4. По этому они одинаковые
            Console.WriteLine("Are obj1 matrix and obj4 matrix equal? - " + obj1.Equals(obj4));
            Console.WriteLine("Are obj1 matrix and obj5 matrix equal? - " + obj1.Equals(obj5));

            //obj1.Equals(obj2) Если сравним эти 2 объекта, то получим ArgumentException("Matrices cannot be compared!");

            Console.ReadKey();
        }
    }

    public class Matrix
    {
        public double[,] Array { get; private set; }
        private readonly int id;

        public Matrix()
        {
            Array = new double[0, 0];
            id = GetHashCode();
            Console.WriteLine("The designer of the matrix #{0}", id);
        }

        public Matrix(int size)
        {
            Array = new double[size, size];
            id = GetHashCode();
            Console.WriteLine("The designer of the matrix #{0}", id);
        }

        public Matrix(int rows, int columns)
        {
            Array = new double[rows, columns];
            id = GetHashCode();
            Console.WriteLine("The designer of the matrix #{0}", id);
        }

        public Matrix(double[,] arr)
        {
            Array = arr;
            id = GetHashCode();
            Console.WriteLine("The designer of the matrix #{0}", id);
        }

        public Matrix(Matrix obj)
        {
            Array = obj.Array;
            id = GetHashCode();
            Console.WriteLine("The designer of the matrix #{0}", id);
        }

        public static bool AdditionCheck(double[,] arr1, double[,] arr2) => arr1.GetLength(0) == arr2.GetLength(0) && arr1.GetLength(1) == arr2.GetLength(1);

        public static bool SubstractionCheck(double[,] arr1, double[,] arr2) => arr1.GetLength(0) == arr2.GetLength(0) && arr1.GetLength(1) == arr2.GetLength(1);

        public static bool MultiplicationCheck(double[,] arr1, double[,] arr2) => arr1.GetLength(1) == arr2.GetLength(0);

        public double MaximumFind(double[,] arr)
        {
            double max = double.MinValue;
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    if (max < arr[i, j])
                    {
                        max = arr[i, j];
                    }
                }
            }
            return max;
        }

        public double MinimumFind(double[,] arr)
        {
            double min = double.MaxValue;
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    if (min < arr[i, j])
                    {
                        min = arr[i, j];
                    }
                }
            }
            return min;
        }

        public static Matrix operator +(Matrix obj1, Matrix obj2)
        {
            if (!AdditionCheck(obj1.Array, obj2.Array))
            {
                throw new ArgumentException("Matrices cannot be addition!");
            }
            else
            {
                Matrix newObject = new Matrix(obj1.Array.GetLength(0));
                for (int i = 0; i < obj1.Array.GetLength(0); i++)
                {
                    for (int j = 0; j < obj2.Array.GetLength(0); j++)
                    {
                        newObject.Array[i, j] = obj1.Array[i, j] + obj2.Array[i, j];
                    }
                }
                return newObject;
            }
        }

        public static Matrix operator -(Matrix obj1, Matrix obj2)
        {
            if (!SubstractionCheck(obj1.Array, obj2.Array))
            {
                throw new ArgumentException("Matrices cannot be substraction!");
            }
            else
            {
                Matrix newObject = new Matrix(obj1.Array.GetLength(0));
                for (int i = 0; i < obj1.Array.GetLength(0); i++)
                {
                    for (int j = 0; j < obj2.Array.GetLength(0); j++)
                    {
                        newObject.Array[i, j] = obj1.Array[i, j] - obj2.Array[i, j];
                    }
                }
                return newObject;
            }
        }

        public static Matrix operator *(Matrix obj1, Matrix obj2)
        {
            if (!MultiplicationCheck(obj1.Array, obj2.Array))
            {
                throw new ArgumentException("Matrices cannot be multiplication!");
            }
            else
            {
                Matrix newObject = new Matrix(obj1.Array.GetLength(0), obj2.Array.GetLength(1));

                for (int i = 0; i < obj1.Array.GetLength(0); i++)
                {
                    for (int j = 0; j < obj2.Array.GetLength(1); j++)
                    {
                        for (int k = 0; k < obj2.Array.GetLength(0); k++)
                        {
                            newObject.Array[i, j] += obj1.Array[i, k] * obj2.Array[k, j];
                        }
                    }
                }
                return newObject;
            }
        }

        public static Matrix operator *(Matrix obj, double number)
        {
            Matrix newObject = new Matrix(obj.Array.GetLength(0), obj.Array.GetLength(1));

            for (int i = 0; i < obj.Array.GetLength(0); i++)
            {
                for (int j = 0; j < obj.Array.GetLength(1); j++)
                {
                    newObject.Array[i, j] = obj.Array[i, j] * number;
                }
            }
            return newObject;
        }

        public static bool operator ==(Matrix obj1, Matrix obj2) => obj1.Equals(obj2);

        public static bool operator !=(Matrix obj1, Matrix obj2) => !obj1.Equals(obj2);

        public override bool Equals(object obj)
        {
            bool flag = true;
            Matrix matrix = (Matrix)obj;

            if ((this.Array.GetLength(0) != matrix.Array.GetLength(0)) || (this.Array.GetLength(1) != matrix.Array.GetLength(1)))
            {
                throw new ArgumentException("Matrices cannot be compared!");
            }
            else
            {
                for (int i = 0; i < this.Array.GetLength(0); i++)
                {
                    for (int j = 0; j < this.Array.GetLength(1); j++)
                    {
                        if (this.Array[i, j] != matrix.Array[i, j])
                        {
                            flag = false;
                            break;
                        }
                    }

                    if (!flag)
                    {
                        return false;
                    }
                }

                return true;
            }
        }

        public override string ToString()
        {
            string array = "";

            for (int i = 0; i < this.Array.GetLength(0); i++)
            {
                for (int j = 0; j < this.Array.GetLength(1); j++)
                {
                    array += this.Array[i, j];
                    array += "\t";
                }
                array += "\n";
            }
            return array;
        }

        ~Matrix()
        {
            Console.WriteLine("The destructor of the matrix #{0}", id);
        }
    }
}
