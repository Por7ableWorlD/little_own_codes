namespace Calculator
{
    public class Number : Operation
    {
        private readonly float meaning;

        public Number(float num)
        {
            meaning = num;
        }

        public override float Multiperation() => meaning;
    }
}
