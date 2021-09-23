namespace Calculator
{
    public abstract class Unary : Operation
    {
        protected Operation one;

        public Unary(Operation op)
        {
            one = op;
        }
    }
}
