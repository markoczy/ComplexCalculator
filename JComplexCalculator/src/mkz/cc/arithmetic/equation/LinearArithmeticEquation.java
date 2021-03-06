/**
 * File: JComplexCalculator::LinearArithmeticEquation.java
 * 
 * Copyright (C) 2016  Aleistar Mark�czy
 * 
 * This file is part of JComplexCalculator.
 *
 * JComplexCalculator is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * JComplexCalculator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with JComplexCalculator.  If not, see <http://www.gnu.org/licenses/>.
 */
package mkz.cc.arithmetic.equation;

import mkz.cc.arithmetic.ArithmeticEquationFactory;
import mkz.cc.arithmetic.ArithmeticOperation;
import mkz.cc.arithmetic.ConstantsArithmetic;
import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.Operation;
import mkz.cc.core.equation.linear.ALinearEquation;
import mkz.util.io.IO;


/**
 * The Class LinearEquation. Implements an array of LinearOperation elements that is solved in a 
 * predefined order ("^" before "/" before "*" before "-" before "+")
 */
public class LinearArithmeticEquation extends ALinearEquation<Double>
{
	public LinearArithmeticEquation()
	{
		super(new Operation[]{
				ConstantsArithmetic.Operations.EXP,
				ConstantsArithmetic.Operations.DIV,
				ConstantsArithmetic.Operations.MPL,
				ConstantsArithmetic.Operations.SUB,
				ConstantsArithmetic.Operations.ADD
				}); // in order of priority ^
	}

	@Override
	protected Equation<Double> _getEquation(Operation aOperation)
	{
		if(!(aOperation instanceof ArithmeticOperation)) 
		{
			IO.dbOutE("Operation is not arithmetic: "+aOperation.getClass().getCanonicalName()); 
			return null;
		}
		
		return ArithmeticEquationFactory.createBasicEquation((ArithmeticOperation)aOperation);
	}
}
