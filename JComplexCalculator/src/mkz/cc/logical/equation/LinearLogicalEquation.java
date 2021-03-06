package mkz.cc.logical.equation;

import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.Operation;
import mkz.cc.core.equation.linear.ALinearEquation;
import mkz.cc.logical.ConstantsLogical;
import mkz.cc.logical.LogicalEquationFactory;
import mkz.cc.logical.LogicalOperation;
import mkz.util.io.IO;

public class LinearLogicalEquation extends ALinearEquation<Boolean>
{
	public LinearLogicalEquation()
	{
		super(new Operation[] { ConstantsLogical.Operations.AND, ConstantsLogical.Operations.OR });
	}

	@Override
	protected Equation<Boolean> _getEquation(Operation aOperation)
	{
		if(!(aOperation instanceof LogicalOperation))
		{
			IO.dbOutE("Operation is not Logical, type is: "+aOperation.getClass().getCanonicalName());
			return null;
		}
		return LogicalEquationFactory.createEquation((LogicalOperation)aOperation);
	}
}
