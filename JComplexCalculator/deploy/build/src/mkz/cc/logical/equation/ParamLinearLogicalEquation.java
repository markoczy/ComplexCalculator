package mkz.cc.logical.equation;

import java.util.ArrayList;

import mkz.cc.core.equation.Operation;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.definition.IParamEquation;
import mkz.util.io.IO;

public class ParamLinearLogicalEquation extends LinearLogicalEquation implements IParamEquation<Boolean>
{
	/** The member params. */
	private ArrayList<IParamEquation<Boolean>> mParams = new ArrayList<IParamEquation<Boolean>>();

	@Override
	public void setParam(String aName, IEquation<Boolean> aValue)
	{
		for(IParamEquation<Boolean> iParam:mParams) iParam.setParam(aName, aValue);
	}
	
	@Override
	public void addOperation(IEquation<Boolean> aEquation, Operation aOperation)
	{
		super.addOperation(aEquation, aOperation);
		if(aEquation instanceof IParamEquation) 
		{
			mParams.add((IParamEquation<Boolean>)aEquation);
			IO.dbOutV("Found param equation. params size now: "+mParams.size());
		}
	}

}
