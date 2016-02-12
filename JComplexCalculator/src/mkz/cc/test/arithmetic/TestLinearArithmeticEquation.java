package mkz.cc.test.arithmetic;

import static org.junit.Assert.*;

import org.junit.Test;

import mkz.cc.arithmetic.equation.LinearArithmeticEquation;
import mkz.cc.core.debug.CCalcException;
import mkz.cc.core.equation.Constant;
import mkz.cc.core.equation.Operation;
import mkz.cc.util.IO;

public class TestLinearArithmeticEquation
{

	@Test
	public void test()
	{
		// 5 - 1 + 4 / 2 * 5 = 14
		//
		LinearArithmeticEquation lEq = new LinearArithmeticEquation();
		lEq.addOperation(new Constant<Double>(5.0), Operation.SUB);
		lEq.addOperation(new Constant<Double>(1.0), Operation.ADD);
		lEq.addOperation(new Constant<Double>(4.0), Operation.DIV);
		lEq.addOperation(new Constant<Double>(2.0), Operation.MPL);
		lEq.addOperation(new Constant<Double>(5.0), Operation.UNDEF);
		
		try
		{
			Double lVal=lEq.getValue();
			IO.SysOutD("5 - 1 + 4 / 2 * 5 =  "+lVal);
			assertEquals(new Double(14),lVal);
		}
		catch (CCalcException e)
		{
			IO.SysOutE(e);
			fail("CCalcException");
		}
	}

}
