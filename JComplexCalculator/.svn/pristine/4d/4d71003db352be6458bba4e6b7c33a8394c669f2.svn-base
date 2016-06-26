package mkz.cc.test.logical;

import mkz.cc.core.equation.Constant;
import mkz.cc.logical.ConstantsLogical;
import mkz.cc.logical.LogicalEquationFactory;
import mkz.cc.logical.equation.LinearLogicalEquation;
import mkz.util.io.IO;

public class TestEquation
{

	public static void main(String[] args)
	{
		try
		{
			Constant<Boolean> lTrue = new Constant<Boolean>(true);
			Constant<Boolean> lFalse = new Constant<Boolean>(false);
			System.out.println("F&F = "+LogicalEquationFactory.createAndEquation().addParam(lFalse).addParam(lFalse).getValue());
			System.out.println("F&T = "+LogicalEquationFactory.createAndEquation().addParam(lFalse).addParam(lTrue).getValue());
			System.out.println("T&F = "+LogicalEquationFactory.createAndEquation().addParam(lTrue).addParam(lFalse).getValue());
			System.out.println("T&T = "+LogicalEquationFactory.createAndEquation().addParam(lTrue).addParam(lTrue).getValue());
			System.out.println();
			System.out.println("F|F = "+LogicalEquationFactory.createOrEquation().addParam(lFalse).addParam(lFalse).getValue());
			System.out.println("F|T = "+LogicalEquationFactory.createOrEquation().addParam(lFalse).addParam(lTrue).getValue());
			System.out.println("T|F = "+LogicalEquationFactory.createOrEquation().addParam(lTrue).addParam(lFalse).getValue());
			System.out.println("T|T = "+LogicalEquationFactory.createOrEquation().addParam(lTrue).addParam(lTrue).getValue());
			System.out.println();
			
			// true AND false OR true -> true
			//
			LinearLogicalEquation lLinEq = new LinearLogicalEquation();
			lLinEq.addOperation(lTrue, ConstantsLogical.Operations.AND);
			lLinEq.addOperation(lFalse, ConstantsLogical.Operations.OR);
			lLinEq.addOperation(lTrue, ConstantsLogical.Operations.CONST);
			System.out.println("true AND false OR true = "+lLinEq.getValue());
			System.out.println();
			
			// true OR false AND true -> true
			//
			lLinEq = new LinearLogicalEquation();
			lLinEq.addOperation(lTrue, ConstantsLogical.Operations.OR);
			lLinEq.addOperation(lFalse, ConstantsLogical.Operations.AND);
			lLinEq.addOperation(lTrue, ConstantsLogical.Operations.CONST);
			System.out.println("true OR false AND true = "+lLinEq.getValue());
			System.out.println();
			
		}
		catch (Exception lE)
		{
			IO.dbOutE(lE);
		}
		
		
	}

}
