package mkz.cc.logical;

import java.util.ArrayList;

import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.function.ParamEquation;
import mkz.cc.core.equation.function.ParamFunction;
import mkz.cc.logical.equation.ParamLinearLogicalEquation;
import mkz.cc.logical.function.BasicLogicFunctionsImpl;
import mkz.util.io.IO;

public class LogicalEquationFactory
{
	public static Equation<Boolean> createAndEquation()
	{
		return new Equation<Boolean>(ConstantsLogical.DisplayNames.AND,BasicLogicFunctionsImpl.AND);
	}
	
	public static Equation<Boolean> createOrEquation()
	{
		return new Equation<Boolean>(ConstantsLogical.DisplayNames.OR,BasicLogicFunctionsImpl.OR);
	}
	
	public static Equation<Boolean> createEquation(LogicalOperation aOp)
	{
		if(aOp.equals(ConstantsLogical.Operations.OR))
		{
			return new Equation<Boolean>(ConstantsLogical.DisplayNames.OR,BasicLogicFunctionsImpl.OR);
		}
		else if(aOp.equals(ConstantsLogical.Operations.AND))
		{
			return new Equation<Boolean>(ConstantsLogical.DisplayNames.AND,BasicLogicFunctionsImpl.AND);
		}
		else
		{
			IO.dbOutE("Operation could not be resolved: "+aOp);
			return null;
		}		
	}
	
	public static Equation<Boolean> createInversion(IEquation<Boolean> aEquation)
	{
		return new Equation<Boolean>(ConstantsLogical.DisplayNames.INV,BasicLogicFunctionsImpl.INV).addParam(aEquation);	
	}
	
	public static Equation<Boolean> createParamInversion(IEquation<Boolean> aEquation)
	{
		return new ParamEquation<Boolean>(ConstantsLogical.DisplayNames.INV,BasicLogicFunctionsImpl.INV).addParam(aEquation);	
	}
	
	public static Equation<Boolean> createDefinitionEquation(String aDefString,ArrayList<String> aParamNames,ParamLinearLogicalEquation aFunction)
	{
		String lName="Custom definition: '"+aDefString+"'";
		ParamFunction<Boolean> lFunction = new ParamFunction<Boolean>(lName, aParamNames, aFunction);
		return new ParamEquation<Boolean>(lName, lFunction);
	}
}
