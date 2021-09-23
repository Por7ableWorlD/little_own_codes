namespace Calculator
{
    public class Minus : Binary
    {
        public Minus(Operation l, Operation r) : base(l, r) { }

        public override float Multiperation() => left.Multiperation() - right.Multiperation();

    }
}
