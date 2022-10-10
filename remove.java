// Java Program to remove a
// given object from the array
import java.util.*;

public class Main {
	public static void main(String args[])
	{

		// Given an array of String objects
		String[] arr
			= { "Geeks", "for", "Geeks", "hello", "world" };

		// object to be removed
		String removeObj = "Geeks";

		// Converting the array to list
		List<String> list
			= new ArrayList<String>(Arrays.asList(arr));

		// Remove all occurrences of given string
		list.removeAll(Arrays.asList(removeObj));

		// Convert back list to array
		// the length of array
		// will also be updated
		arr = list.toArray(new String[0]);

		// Print the updated array
		System.out.println("Updated array:- ");
		for (int ind = 0; ind < arr.length; ind++) {
			System.out.println(arr[ind]);
		}
	}
}
