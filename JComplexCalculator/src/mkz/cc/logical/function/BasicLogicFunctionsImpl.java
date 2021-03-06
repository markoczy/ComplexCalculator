package mkz.cc.logical.function;

import mkz.cc.core.debug.equation.InvalidParamCountException;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.definition.IFunction;
import mkz.cc.logical.ConstantsLogical;
import mkz.util.io.IO;

public class BasicLogicFunctionsImpl
{
	/** The Constant AND. */
	public static final IFunction<Boolean> AND=(aArr)->
	{
		IO.dbOutV("Solving AND.");
		
		if(aArr.size()<2)throw new InvalidParamCountException(ConstantsLogical.DisplayNames.AND,aArr.size());
		Boolean rVal=true;
		
		// eg. 1 & 1 & 0 = 0
		for(IEquation<Boolean> iEq:aArr) rVal&=iEq.getValue();
		return rVal;
	};
	
	/** The Constant OR. */
	public static final IFunction<Boolean> OR=(aArr)->
	{
		IO.dbOutV("Solving OR.");
		
		if(aArr.size()<2)throw new InvalidParamCountException(ConstantsLogical.DisplayNames.OR,aArr.size());
		Boolean rVal=false;
		
		// eg. 0 | 0 | 1 = 1
		for(IEquation<Boolean> iEq:aArr) rVal|=iEq.getValue();
		return rVal;
	};
	
	public static final IFunction<Boolean> INV=(aArr)->
	{
		IO.dbOutV("Solving INV.");
		
		if(aArr.size()!=1)throw new InvalidParamCountException(ConstantsLogical.DisplayNames.INV,aArr.size());
		return !aArr.get(0).getValue();
	};
}
