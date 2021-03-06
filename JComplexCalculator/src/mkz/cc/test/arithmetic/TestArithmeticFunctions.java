package mkz.cc.test.arithmetic;

import static org.junit.Assert.assertEquals;

import java.util.ArrayList;
import java.util.Arrays;

import org.junit.Test;

import mkz.cc.arithmetic.ArithmeticEquationFactory;
import mkz.cc.arithmetic.ConstantsArithmetic;
import mkz.cc.arithmetic.equation.ParamLinearArithmeticEquation;
import mkz.cc.arithmetic.function.ArithmeticFunctions;
import mkz.cc.core.equation.Constant;
import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.Operation;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.function.Variable;
import mkz.util.io.IO;

@SuppressWarnings(value = { "all" })
public class TestArithmeticFunctions
{

	@Test
	public void test()
	{
		// Test 1: exp(5,2)
		//
		Equation<Double> lExpEq = ArithmeticEquationFactory.createFuncionEquation("exp");
		Double lVal=lExpEq.addParam(new Constant<Double>(5.0)).addParam(new Constant<Double>(2.0)).getValue();
		IO.dbOutD("exp(5,2) = "+lVal);
		assertEquals(new Double(25),lVal);
	
		// Test 2: sum(1,2,3,4)
		//
		Equation<Double> lSumEq = ArithmeticEquationFactory.createFuncionEquation("sum");
		ArrayList<IEquation<Double>>lParams =new ArrayList<IEquation<Double>>();
		lParams.add(new Constant<Double>(1.0));
		lParams.add(new Constant<Double>(2.0));
		lParams.add(new Constant<Double>(3.0));
		lParams.add(new Constant<Double>(4.0));
		lSumEq.setParams(lParams);
		lVal=lSumEq.getValue();
		IO.dbOutD("sum(1,2,3,4) = "+lVal);
		assertEquals(new Double(10),lVal);
		
		// Test 3: Create Function test(x):=x*2
		//
		ParamLinearArithmeticEquation lFunction= new ParamLinearArithmeticEquation();
		lFunction.addOperation(new Variable<Double>("x"), ConstantsArithmetic.Operations.MPL);
		lFunction.addOperation(new Constant<Double>(2.0), ConstantsArithmetic.Operations.CONST);
		ArithmeticFunctions.getInstance().addFunction("test", "My test function", new ArrayList<String>(Arrays.asList(new String[]{"x"})),"test(x):=x*2",lFunction);
		Equation<Double> lTestEq=ArithmeticEquationFactory.createFuncionEquation("test");
		lVal=lTestEq.addParam(new Constant<Double>(5.0)).getValue();
		IO.dbOutD("test(x):=x*2 -> test(5)="+lVal);
		assertEquals(new Double(10),lVal);
		
	}

}
