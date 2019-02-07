#include <iostream>
#include <string>


    class IFood{
    };
 
    class Bread : IFood{
    }
    class Triangle : IShape { }
 
    // liczby
    interface INumber { }
 
    class RealNumber : INumber { }
    class ComplexNumber : INumber { }
 
    // fabryka abstrakcyjna rodziny obiektów
    abstract class MathTestFactory
    {
        public abstract IShape CreateShape();
        public abstract INumber CreateNumber();
    }
        
    // konkretna fabryka rodziny obiektów
    class PrimarySchoolTestFactory : MathTestFactory
    {
        public override IShape CreateShape()
        {
            return new Square();
        }
 
        public override INumber CreateNumber()
        {
            return new RealNumber();
        }
    }
 
    // konkretna fabryka rodziny obiektów
    class HighSchoolTestFactory : MathTestFactory
    {
        public override IShape CreateShape()
        {
            return new Triangle();
        }
 
        public override INumber CreateNumber()
        {
            return new ComplexNumber();
        }
    }
 
    // klasa klienta (kontekst wykonania fabryki)
    class MathTest
    {
        private MathTestFactory mathTestFactory;
 
        public MathTest(MathTestFactory mathTestFactory)
        {
            this.mathTestFactory = mathTestFactory;
        }
 
        public void GenerateTest()
        {
            var shape = this.mathTestFactory.CreateShape();
            var number = this.mathTestFactory.CreateNumber();
            System.Console.WriteLine("Test wygenerowany");
        }
    }
 
    static void Main(string[] args)
    {
        MathTest mathTest;
 
        mathTest = new MathTest(new PrimarySchoolTestFactory());
        mathTest.GenerateTest(); // łatwy test przy użyciu PrimarySchoolTestFactory()
 
        mathTest = new MathTest(new HighSchoolTestFactory());
        mathTest.GenerateTest(); // trudny test przy użyciu PrimarySchoolTestFactory()
    }