using System;

namespace Calculator
{
    public class Expression
    {
        private string temp_expr;
        private int pos;

        public Expression(string expr) 
        { 
            temp_expr = expr; 
        }

        public float Calculate()
        {
            pos = 0;
            Operation output = ThirdPriority();

            return (output != null) ? output.Multiperation() : 0.0f;
        }

        private Operation ThirdPriority()
        {
            Operation result = SecondPriority();

            for (; ; )
            {
                if (Match('+'))
                {
                    result = new Plus(result, SecondPriority());
                }
                else if (Match('-'))
                {
                    result = new Minus(result, SecondPriority());
                }
                else
                {
                    return result;
                }
            }
        }

        private Operation SecondPriority()
        {
            Operation result = FirstPriority();
            for (; ; )
            {
                if (Match('*'))
                {
                    result = new Multiply(result, FirstPriority());
                }
                else if (Match('/'))
                {
                    result = new Divide(result, FirstPriority());
                }
                else
                {
                    return result;
                }
            }
        }

        private Operation FirstPriority()
        {
            Operation result = null;

            if (Match('-'))
            {
                result = new Negation(ThirdPriority());
            }
            else if (Match('('))
            {
                result = ThirdPriority();

                if (!Match(')'))
                {
                    Console.WriteLine("Missing ')'");
                }
            }
            else
            {
                float value = 0.0f;
                int start_pos = pos;

                while (pos < temp_expr.Length && (char.IsDigit(temp_expr[pos]) || temp_expr[pos] == '.'))
                {
                    pos++;
                }

                try 
                {
                    value = float.Parse(temp_expr.Substring(start_pos, pos - start_pos));
                }
                catch  
                {
                    Console.WriteLine("Can't parse '" + temp_expr.Substring(start_pos, pos - start_pos) + "'");
                
                }

                result = new Number(value);
            }

            return result;
        }

        private bool Match(char ch)
        {
            if (pos >= temp_expr.Length)
            {
                return false;
            }

            while (temp_expr[pos] == ' ')
            {
                pos++;
            }

            if (temp_expr[pos] == ch)
            {
                pos++;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
