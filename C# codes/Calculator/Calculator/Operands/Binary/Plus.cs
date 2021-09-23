namespace Calculator
{
    public class Plus : Binary
    {
        public Plus(Operation l, Operation r) : base(l, r) { }

        public override float Multiperation() => left.Multiperation() + right.Multiperation();
    }
}
