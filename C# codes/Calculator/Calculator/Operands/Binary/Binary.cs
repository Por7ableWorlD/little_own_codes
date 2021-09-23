namespace Calculator
{
    public abstract class Binary : Operation
    {
        protected Operation left, right;

        public Binary(Operation l, Operation r)
        {
            left = l;
            right = r;
        }
    }
}
