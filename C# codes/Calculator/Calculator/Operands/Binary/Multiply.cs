namespace Calculator
{
    class Multiply : Binary
    {
        public Multiply(Operation l, Operation r) : base(l, r) { }

        public override float Multiperation() => left.Multiperation() * right.Multiperation();
    }
}
