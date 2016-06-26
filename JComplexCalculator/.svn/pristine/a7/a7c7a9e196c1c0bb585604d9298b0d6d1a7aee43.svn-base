/**
 * File: JComplexCalculator::ParamFunction.java
 * 
 * Copyright (C) 2016  Aleistar Markóczy
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
package mkz.cc.core.equation.function;

import java.util.ArrayList;

import mkz.cc.core.debug.CCalcException;
import mkz.cc.core.debug.equation.InvalidParamCountException;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.definition.IFunction;
import mkz.cc.core.equation.definition.IParamEquation;

/**
 * The Class ParamFunction. Implements a Parsed function where all function params 
 * are used to set recursively the functions values by name (see getValue).
 *
 * @param <T> the generic type
 */
public class ParamFunction<T> implements IFunction<T>
{
	
	/** The member name. */
	private String mName=null;
	
	/** The member param names. */
	private ArrayList<String> mParamNames = new ArrayList<String>();
	
	/** The member equation. */
	IParamEquation<T> mEquation=null;

	/**
	 * Instantiates a new param function.
	 *
	 * @param aName the reference name
	 * @param aEquation the reference equation
	 */
	public ParamFunction(String aName,IParamEquation<T> aEquation)
	{
		mName=aName;
		mEquation=aEquation;
	}
	
	/**
	 * Instantiates a new param function.
	 *
	 * @param aName the reference name
	 * @param aParamNames the reference param names
	 * @param aEquation the reference equation
	 */
	public ParamFunction(String aName,ArrayList<String> aParamNames,IParamEquation<T> aEquation)
	{
		mName=aName;
		mParamNames=aParamNames;
		mEquation=aEquation;
	}
	
	/**
	 * Adds the param.
	 *
	 * @param aName the reference name
	 * @return the param function
	 */
	public ParamFunction<T> addParam(String aName)
	{
		mParamNames.add(aName);
		return this;
	}
	
	/* (non-Javadoc)
	 * @see mkz.cc.core.equation.IFunction#getValue(java.util.ArrayList)
	 */
	@Override
	public T getValue(ArrayList<IEquation<T>> aEqArr) throws CCalcException
	{
		if(aEqArr.size()!=mParamNames.size())throw new InvalidParamCountException(mName,aEqArr.size());
		
		for(int i=0;i<aEqArr.size();i++)
		{
			mEquation.setParam(mParamNames.get(i), aEqArr.get(i));
		}
		
		return mEquation.getValue();
	}

}
