/**
 * File: TestEquations_.java
 *
 * @author Aleistar Markoczy
 */
package mkz.cc.test.arithmetic;

import static org.junit.Assert.*;

import java.util.ArrayList;

import org.junit.Test;

import mkz.cc.arithmetic.ArithmeticEquationFactory;
import mkz.cc.core.equation.Constant;
import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.definition.IEquation;
import mkz.util.io.IO;

/**
 * @author Aleistar
 *
 */
public class TestEquations
{

	@Test
	public void test()
	{
		// Extended definition (for demonstration purpose)
		//
		ArrayList<IEquation<Double>> lEq = new ArrayList<IEquation<Double>>();
		lEq.add(new Constant<Double>(12.0));
		lEq.add(new Constant<Double>(10.0));
		Equation<Double> lAdd = ArithmeticEquationFactory.createAddition();
		lAdd.setParams(lEq);
		IO.dbOutD("12 + 10 = " + lAdd.getValue());
		assertEquals(new Double(22.0), lAdd.getValue());

		// Fast Definition
		//
		assertEquals(new Double(2.0), ArithmeticEquationFactory.createSubtraction().addParam(new Constant<Double>(12.0)).addParam(new Constant<Double>(10.0)).getValue());
		assertEquals(new Double(120.0), ArithmeticEquationFactory.createMultiplication().addParam(new Constant<Double>(12.0)).addParam(new Constant<Double>(10.0)).getValue());
		assertEquals(new Double(6.0), ArithmeticEquationFactory.createDivision().addParam(new Constant<Double>(12.0)).addParam(new Constant<Double>(2.0)).getValue());

		// etc..
	}

}
