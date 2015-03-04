# Drupal User data - how to store user specific content without fields
All accompanying code for the tutorial available at http://www.codesidekick.com/blog/user-data-how-store-user-specific-content-without-fields.

## Usage
### Set data to the user object.
```php
global $user;
$account = entity_metadata_wrapper('user', $user);
$account->employee_number->set(60000);
entity_save('user', $account);
```
### Get data from the user object.
```php
global $user;
$account = entity_metadata_wrapper('user', $user);
$employee_number = $account->employee_number->value();
```
