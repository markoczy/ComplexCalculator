/**
 * File: JComplexCalculator::IO.java
 * 
 * This file was created by Aleistar Mark�czy for himself,
 * and the public domain. Please feel free to use/improve/sell this file
 * along with your own projects.
 * 
 */
package mkz.cc.util;

import java.io.PrintWriter;
import java.io.StringWriter;

/**
 * A basic homebrew logger for Java. Originally made to have a highly customizable (i.e. open source) 
 * logger without using any 3rd party libs.
 */
public class IO 
{
	/** The member error level. */
	private static int mErrorLevel; // 3 = DEBUG is set as default

	/** The Constant LOG_FATAL. */
	private static final int LOG_FATAL=0;
	
	/** The Constant LOG_ERROR. */
	private static final int LOG_ERROR=1;
	
	/** The Constant LOG_WARN. */
	private static final int LOG_WARN=2;
	
	/** The Constant LOG_DEBUG. */
	private static final int LOG_DEBUG=3;
	
	/** The Constant LOG_VERBOSE. */
	private static final int LOG_VERBOSE=4;
	
	/** The Constant NEWLINE. Platform specific newline char */
	private static final String NEWLINE = System.getProperty("line.separator");
	
	
	/**
	 * Sets the current log level.
	 * 0: FATAL only ; 1: ERROR ; 2: WARNING ; 3: DEBUG ; 4: VERBOSE
	 *
	 * @param aLevel the new log level
	 */
	public static void setLogLevel(int aLevel)
	{
		mErrorLevel=aLevel;
	}
	
	/**
	 * Output current method tree and a message text, 
	 * log-level: Verbose.
	 *
	 * @param message the message
	 */
	public static void SysOutV(String message)
	{
		SysOut(message, LOG_VERBOSE);
	}
	
	/**
	 * Output current method tree and a message text, 
	 * log-level: Debug.
	 *
	 * @param message the message
	 */
	public static void SysOutD(String message)
	{
		SysOut(message, LOG_DEBUG);
	}
	
	/**
	 * Output current method tree and a message text, 
	 * log-level: Warning.
	 *
	 * @param message the message
	 */
	public static void SysOutW(String message)
	{
		SysOut(message, LOG_WARN);
	}
	
	/**
	 * Output current method tree and a message text, 
	 * log-level: Error.
	 *
	 * @param message the message
	 */
	public static void SysOutE(String message)
	{
		SysOut(message, LOG_ERROR);
	}
	
	/**
	 * Output current method tree and a message text, 
	 * log-level: Error.
	 *
	 * @param t the message
	 */
	public static void SysOutE(Throwable t)
	{
		StringBuilder sb = new StringBuilder();
		sb.append("Exception thrown: "+t+", Message: "+t.getMessage()+NEWLINE);
		sb.append("*************************************************************");
		sb.append(NEWLINE+"The stack trace was:"+NEWLINE);
		sb.append(_getStackTrace(t));
		sb.append("*************************************************************");
		
//		SysOut("Exception thrown: "+t+", Message: "+t.getMessage()+", Stack Trace:\n"+_getStackTrace(t), LOG_ERROR);
		SysOut(sb.toString(), LOG_ERROR);
	}
	
	
	/**
	 * Output current method tree and a message text, 
	 * log-level: Fatal Error (will always be shown).
	 *
	 * @param t the message
	 */
	public static void SysOutF(Throwable t)
	{
		StringBuilder sb = new StringBuilder();
		sb.append("Exception thrown: "+t+", Message: "+t.getMessage()+NEWLINE);
		sb.append("*************************************************************");
		sb.append(NEWLINE+"The stack trace was:"+NEWLINE);
		sb.append(_getStackTrace(t));
		sb.append("*************************************************************");
		
		SysOut(sb.toString(), LOG_FATAL);
//		SysOut("Exception thrown: "+t+", Message: "+t.getMessage()+", Stack Trace:\n"+_getStackTrace(t), LOG_FATAL);
	}
	
	/**
	 * Output current method tree and a message text, 
	 * log-level: Fatal Error (will always be shown).
	 *
	 * @param message the message
	 */
	public static void SysOutF(String message)
	{
		SysOut(message, LOG_FATAL);
	}
	
	/**
	 * System out - Shows current method tree
	 * and a debug message (if provided that the Application
	 * error level is greater or equal to the message error level).
	 *
	 * @param message the message
	 * @param errorLevel the error level
	 */
	private static void SysOut(String message, int errorLevel)
	{
		if(mErrorLevel<errorLevel)
		{
			return;
		}
		
		StringBuilder msg = new StringBuilder();
		
		msg.append(getErrorLvTxt(errorLevel));
		msg.append(".");
		
		StackTraceElement[] el=Thread.currentThread().getStackTrace();

		if(el.length>3)
		{
			StackTraceElement e3=el[3];
			
			msg.append(e3.getClassName());
			msg.append("::");
			msg.append(e3.getMethodName());
			msg.append(": ");
			msg.append(message);
		}
		
		System.out.println(msg.toString());
	}
	
	/**
	 * Gets the error level text.
	 *
	 * @param level the level
	 * @return the error level text
	 */
	private static String getErrorLvTxt(int level)
	{
		switch(level)
		{
		case(LOG_VERBOSE):
			return "Verbose"; 
		case(LOG_DEBUG):
			return "Debug"; 
		case(LOG_WARN):
			return "WARNING"; 
		case(LOG_ERROR):
			return "ERROR"; 
		case(LOG_FATAL):
			return "!!FATAL!!"; 
		default:
			return "<UNKNOWN>"; 
		}
	}
	
	/**
	 * [restricted] get stack trace.
	 *
	 * @param t the t
	 * @return the string
	 */
	private static String _getStackTrace(Throwable t)
	{
		StringWriter sw = new StringWriter();
		PrintWriter pw = new PrintWriter(sw);
		t.printStackTrace(pw);
		return sw.toString();
	}
	
}
