namespace Calculator
{
    public class Negation : Unary
    {
        public Negation(Operation n) : base(n) { }

        public override float Multiperation() => -one.Multiperation();
    }
}
