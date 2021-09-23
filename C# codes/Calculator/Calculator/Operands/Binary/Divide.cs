using System;

namespace Calculator
{
    class Divide : Binary
    {
        public Divide(Operation l, Operation r) : base(l, r) { }

        public override float Multiperation()
        {
            float right_eval = right.Multiperation();
            if (right_eval == 0.0f)
            {
                Console.WriteLine("Devide by zero");
            }

            return (right_eval != 0.0f) ? (left.Multiperation() / right_eval) : float.MaxValue;
        }
    }
}
