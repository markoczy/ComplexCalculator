package mkz.cc.test.arithmetic;

import static org.junit.Assert.*;

import org.junit.Test;

import mkz.cc.arithmetic.ConstantsArithmetic;
import mkz.cc.arithmetic.equation.LinearArithmeticEquation;
import mkz.cc.core.debug.CCalcException;
import mkz.cc.core.equation.Constant;
import mkz.cc.core.equation.Operation;
import mkz.util.io.IO;

@SuppressWarnings(value = { "all" })
public class TestLinearArithmeticEquation
{

	@Test
	public void test()
	{
		// 5 - 1 + 4 / 2 * 5 = 14
		//
		LinearArithmeticEquation lEq = new LinearArithmeticEquation();
		lEq.addOperation(new Constant<Double>(5.0), ConstantsArithmetic.Operations.SUB);
		lEq.addOperation(new Constant<Double>(1.0), ConstantsArithmetic.Operations.ADD);
		lEq.addOperation(new Constant<Double>(4.0), ConstantsArithmetic.Operations.DIV);
		lEq.addOperation(new Constant<Double>(2.0), ConstantsArithmetic.Operations.MPL);
		lEq.addOperation(new Constant<Double>(5.0), ConstantsArithmetic.Operations.UNDEF);
		
		try
		{
			Double lVal=lEq.getValue();
			IO.dbOutD("5 - 1 + 4 / 2 * 5 =  "+lVal);
			assertEquals(new Double(14),lVal);
		}
		catch (CCalcException e)
		{
			IO.dbOutE(e);
			fail("CCalcException");
		}
	}

}
