/**
 * File: JComplexCalculator::VersionInfo.java
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
package mkz.cc;

/**
 * The Class VersionInfo. Represents the current API version.
 */
public class VersionInfo
{
	/** The member release. */
	private static int mRelease = 0;
	
	/** The member subrelease. */
	private static int mSubrelease = 2;
	
	/** The member build. */
	private static int mBuild = 7;
	
	/**
	 * Gets the version.
	 *
	 * @return the version
	 */
	public static String getVersion()
	{
		return mRelease+"."+mSubrelease+"."+mBuild;
	}
	
	/**
	 * Gets the release.
	 *
	 * @return the release
	 */
	public static int getRelease()
	{
		return mRelease;
	}
	
	/**
	 * Gets the sub releases.
	 *
	 * @return the sub releases
	 */
	public static int getSubReleases()
	{
		return mSubrelease;
	}
	
	/**
	 * Gets the build.
	 *
	 * @return the build
	 */
	public static int getBuild()
	{
		return mBuild;
	}
}